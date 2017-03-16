#!/usr/bin/env python3

# (C) 2014 Susanne Oberhauser-Hirschoff
# The MIT License applies: http://opensource.org/licenses/MIT

# Google codejam 2014
# Problem C. Minesweeper Master

from codejam_2014 import *

class XX: pass
class Codejam_2014_D(Codejam_2014):
    def __init__(self):
        Codejam_2014.__init__(self)
    def parse_one_problem_set(self):
        problem = XX()
        problem.n_blocks = int(self.file.readline())
        problem.naomi_blocks    = [float(x) for x in self.file.readline().split()]
        problem.ken_blocks      = [float(x) for x in self.file.readline().split()]
        assert(len(problem.naomi_blocks) == problem.n_blocks)
        assert(len(problem.ken_blocks) == problem.n_blocks)
        assert(len(set(problem.naomi_blocks).union(problem.ken_blocks)) == 2*problem.n_blocks)
        #print(problem.__dict__)
        return problem

    def solve_problem(self, problem):
        # claim: the optimal strategy for Ken is to always play the lightest
        # block that is heavier than the one naomi played, or, if Ken has no
        # such block, then to play the lightest block he has at all.
        #
        # rationale:
        #
        # Kens blocks fall into three categories: those heavyer than any of
        # Naomis blocks, those lighter than any of Naomis blocks and those
        # where Naomi has both lighter and heavier blocks.
        #
        # No matter the strategy, the heavier ones will all win and the
        # lighter ones will all loose.  So Kens strategy determines how the
        # blocks score, where Naomi has both heavier and lighter ones.
        # 
        # Kens strategy, if optimal, has to deal with any order Naomi is going
        # to present her blocks.  So for Ken, the strategy must be to juggle
        # the _probablities_ such that he if anything increases the number of
        # heavyer-than-any blocks and decreases the number of his
        # lighter-than-any blocks, but not the other way 'round.
        # 
        # Now the winning potential of each block is the number of potentially
        # lighter blocks while the losing potential of each block is the
        # number of potentially heavyer blocks.
        #
        # So Ken maximizes his potential by spending as little as possible on
        # each move.  Which is: if he has to lose, he loses with the lowest
        # weight.  If he can win, he wins with the lowest possible weight.
        # 
        # 
        # claim: the optimal strategy for Naomi for Deceitful War is to use
        # her certainly loosing blocks to make Ken play his heaviest blocks
        # (claiming almost that weight), and to use just heavy enough blocks
        # to make him play his lightest blocks (claiming a maximum weight).
        #
        # claim: for War, the outcome for Naomi is the same no matter how she
        # plays.
        # 

        solution=XX()

        # Ken's optimum algorithm:
        # if Naomi's block is lighter than my heaviest block:
        #    return my just-a-bit heavier block
        # else:
        #    return my lightest block

        # Naomis War 'strategy':  go from heaviest to lightest.
        # now, for the purpose of this simulation, this is the same as:
        # if my (Naomi's) heaviest block is heavier than Ken's heaviest block:
        #    get Ken's lightest (as per his strategy)
        # else:
        #    get Ken's heaviest --- my next one will be lighter, as per my
        #    stragtey, so his next one will match my next one the same way.

        from collections import deque
        
        ken_blocks = deque(sorted(problem.ken_blocks))
        # sort from heaviest to lightest
        naomi_blocks = reversed(sorted(problem.naomi_blocks))
        naomi_war_score = 0

        #print(naomi_blocks)
        for block in naomi_blocks:
            #print(block, ken_blocks)
            # heavier than his heaviest?
            if block > ken_blocks[-1]:
                # get his lightest and win
                ken_blocks.popleft()
                naomi_war_score += 1
            else:
                # get his heaviest
                ken_blocks.pop()

        # Naomis Deceitful War strategy:
        # if my lightest block is lighter than Ken's lightest block:
        #    pull Ken's heaviest (claim that weight -epsilon) with my lightest
        # else:
        #    pull Ken's lightest (claim that weight +epsilon) with my lightest
        #    (still heavier than his lightest)

        ken_blocks = deque(sorted(problem.ken_blocks))
        naomi_blocks = sorted(problem.naomi_blocks)

        #print(naomi_blocks)
        naomi_deceitful_score = 0
        for block in naomi_blocks:
            #print(block, ken_blocks)
            # lighter than his lightest?
            if block < ken_blocks[0]:
                # get his heaviest
                ken_blocks.pop()
            else:
                # get his lightest and win
                ken_blocks.popleft()
                naomi_deceitful_score += 1
        
        solution.naomi_war_score       = naomi_war_score
        solution.naomi_deceitful_score = naomi_deceitful_score
        return solution

    def str_solution(self, solution):
        return "{0} {1}".format(solution.naomi_deceitful_score, solution.naomi_war_score)



if __name__ == "__main__":
    import sys
    a = Codejam_2014_D()
    a.run(sys.argv[1])
