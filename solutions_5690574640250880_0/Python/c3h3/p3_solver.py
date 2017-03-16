'''
Created on Apr 13, 2014

@author: c3h3
'''

import sys
import numpy as np
from PlaYdata.util import tools


def board2str(board_array):
    return " ".join(map(lambda one_row: " ".join(one_row), board_array.astype(str)))

def get_nonzero_points(board_array):
    return zip(*np.nonzero(board_array))

def how_many_nonzeros(board_array):
    return len(get_nonzero_points(board_array))

def boundary_checker(board_array, nbhd_slice):
    sub_board = board_array[nbhd_slice]
    return len(get_nonzero_points(sub_board)) != reduce(lambda x, y:x * y, sub_board.shape)



class MileGame(object):
    def __init__(self, nrow, ncol, nmile):
        self.nrow = nrow
        self.ncol = ncol
        self.nmile = nmile
        self.game_size = self.nrow * self.ncol
        self.n_spaces = self.game_size - self.nmile

        self.try_cases = []
        self.tried_cases = []
        self.solution_cases = []


        if self.n_spaces > 0:
            self.add_try_case(board2str(np.zeros((nrow, ncol), dtype=int)))

    @property
    def _has_try_cases(self):
        return len(self.try_cases) > 0

    @property
    def _has_solution(self):
        return len(self.solution_cases) > 0

    @property
    def _try_cases_to_boards(self):
        return map(self.str2boarrd, self.try_cases)

    def get_nbhd_slice(self, point):
        ii, jj = point[0], point[1]
        return slice(max(0, ii - 1), min(ii + 2, self.nrow)), slice(max(0, jj - 1), min(jj + 2, self.ncol))

    def str2boarrd(self, board_str):
        return np.array(board_str.split()).reshape((self.nrow, self.ncol)).astype(int)

    def add_try_case(self, board_str):
        if (board_str in self.tried_cases) or (board_str in self.try_cases):
            pass
        else:
            self.try_cases.append(board_str)

    def add_tried_case(self, board_str):
        if board_str in self.tried_cases:
            pass
        else:
            self.tried_cases.append(board_str)

    def get_boundary_points(self, board_array):
        nonzero_points = get_nonzero_points(board_array)
        nonzero_points_nbhd_slices = map(self.get_nbhd_slice, nonzero_points)
        return [xx[0] for xx in zip(nonzero_points, nonzero_points_nbhd_slices) if boundary_checker(board_array, xx[1])]


    def gen_try_boards(self, board_array):
        board_array_n_nonzeros = len(get_nonzero_points(board_array))
        if board_array_n_nonzeros < self.n_spaces:

            if board_array_n_nonzeros < 1:
                try_board = board_array.copy()
                try_board[0, 0] = 1
                self.add_try_case(board2str(try_board))

            else:

                board_array_bdry_pts = self.get_boundary_points(board_array)
                board_array_bdry_nbhd_slices = map(self.get_nbhd_slice, board_array_bdry_pts)

                # print "~~~~~~~~~~~~~~~~~~~~~~~~~"
                # print "[in gen_try_boards]"
                # print "[in case board_array_n_nonzeros >= 1]"
                # print "board_array = ",board_array
                # print "board_array_bdry_pts = ",board_array_bdry_pts
                # print "board_array_bdry_nbhd_slices = ",board_array_bdry_nbhd_slices

                for one_brdy_nbhd_silce in board_array_bdry_nbhd_slices:
                    # print "one_brdy_nbhd_silce = ", one_brdy_nbhd_silce
                    try_board_array = board_array.copy()
                    try_board_array[one_brdy_nbhd_silce] = 1
                    # print "try_board_array = ",try_board_array
                    self.add_try_case(board2str(try_board_array))



        else:
            return []


    def search_solution(self):
        while self._has_try_cases and (not(self._has_solution)):
            one_board_str = self.try_cases.pop()
            one_board = self.str2boarrd(one_board_str)
            # print "one_board = ",one_board
            if how_many_nonzeros(one_board) == self.n_spaces:
                self.solution_cases.append(one_board_str)
            else:
                self.gen_try_boards(one_board)

            self.add_tried_case(one_board_str)

    def print_solution(self):
        if self._has_solution:
            sol_array = np.array(["*", "."])[self.str2boarrd(self.solution_cases[0])].copy()
            sol_array[0, 0] = "c"
            print "\n".join(map(lambda one_row:"".join(one_row), sol_array.tolist()))
        else:
            print "Impossible"



if __name__ == '__main__':
    assert len(sys.argv) > 1
    input_filename = str(sys.argv[1])
    # input_filename = "p3_test.in"

    with open(input_filename, "r") as input_file:
        input_file_read = input_file.read()

    input_file_lines = input_file_read.split("\n")
    input_file_lines
    n_cases = int(input_file_lines[0])
    for i_case in range(n_cases):
        nrow, ncol, nmile = tuple(map(int, input_file_lines[1:][i_case].split()))
        print "Case #%d:" % (i_case + 1,)
        g1 = MileGame(nrow, ncol, nmile)
        g1.search_solution()
        g1.print_solution()

