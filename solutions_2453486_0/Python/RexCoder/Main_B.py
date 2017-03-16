from __future__ import division;
from bisect import *;
from fractions import Fraction;
import sys;
import math;
import io;

INF = 987654321987654321987654321;

def readint(delimiter=' ') :
	return map(int, raw_input().split(delimiter));

def readstr() :
	return raw_input().split();

def readfloat() :
	return map(float, raw_input().split());

def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]
    raise ValueError


def bin_search(a, x, left, right) :

    while left<=right :
        mid = (left + right)//2;
        
        if a[mid] == x :
            return mid;
        elif a[mid] < x :
            left = mid + 1; 
        elif a[mid] > x :
            right = mid - 1;
                       
        pass
    
    return -1;
    pass

if __name__ == '__main__':
	
    def valid(board) :
        x_win = False;
        o_win = False;
        dot_count = 0;
        for ii in xrange(4) :
            x_now = 0;
            o_now = 0;
            # check row #
            for jj in xrange(4) :
                if board[ii][jj] == '.' :
                    dot_count += 1;
                    
                if board[ii][jj] == 'X' or board[ii][jj] == 'T' :
                    x_now += 1;

                if board[ii][jj] == 'O' or board[ii][jj] == 'T' :
                    o_now += 1;

            if x_now == 4 :
                x_win = True;
                break;
            elif o_now == 4:
                o_win = True;
                break;

            x_now = 0;
            o_now = 0;
            # check column #
            for jj in xrange(4) :
                if board[jj][ii] == 'X' or board[jj][ii] == 'T' :
                    x_now += 1;

                if board[jj][ii] == 'O' or board[jj][ii] == 'T' :
                    o_now += 1;

            if x_now == 4 :
                x_win = True;
                break;
            elif o_now == 4:
                o_win = True;
                break;

        o_now = 0;
        x_now = 0;
        # diagonal left upper to right bottom #
        for ii in xrange(4) :
            if board[ii][ii] == 'X' or board[ii][ii] == 'T':
                x_now += 1;
            if board[ii][ii] == 'O' or board[ii][ii] == 'T' :
                o_now += 1;

        if x_now == 4 :
            x_win = True;
        elif o_now == 4 :
            o_win = True;

        o_now = 0;
        x_now = 0;
        # diagonal left bottom to right upper #
        for ii in xrange(4) :
            if board[3-ii][ii] == 'X' or board[3-ii][ii] == 'T':
                x_now += 1;
            if board[3-ii][ii] == 'O' or board[3-ii][ii] == 'T' :
                o_now += 1;

        if x_now == 4 :
            x_win = True;
        elif o_now == 4 :
            o_win = True;

        if x_win :
            return "X won";
        elif o_win :
            return "O won";
        else :
            if dot_count == 0 :
                return "Draw";
            else :
                return "Game has not completed";
        pass


    tc = input();
    mat = [['.' for _ in xrange(4)] for _ in xrange(4)]
    for ii in xrange(tc) :
        for jj in xrange(4) :
            now = raw_input();
            for kk in xrange(4) :
                mat[jj][kk] = now[kk];
                pass
            pass
        status = valid(mat);
        print "Case #%d: %s"%(ii+1, status);            
        if ii != tc-1 :
            raw_input();
        pass




    pass