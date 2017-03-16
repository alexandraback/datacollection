#!/usr/bin/env python3

# (C) 2014 Susanne Oberhauser-Hirschoff
# The MIT License applies: http://opensource.org/licenses/MIT

# Google codejam 2014
# Problem B. Cookie Clicker Alpha

from codejam_2014 import *

class XX: pass
class Codejam_2014_B(Codejam_2014):
    def parse_one_problem_set(self):
        # one problem set consists of two identical blocks
        problem = XX()
        # c: cost of farm
        # f: additional cookies per second
        # x: goal
        problem.c, problem.f, problem.x = [float(x) for x in self.file.readline().split()]
        #print(problem.__dict__)
        return problem

    def solve_problem(self, problem):

        # The problem looks like it can be solved iteratively (build one
        # factory after the other until the cookies are clicked).

        # just before building another factory, check if with that factory it
        # will be faster or not, before building it.

        productivity_f    = 2 # cookies per second
        time_spent_so_far = 0.0 # seconds

        while True:
            remaining_time_with_current_productivity = problem.x / productivity_f

            time_to_next_factory = problem.c / productivity_f
        
            # if it takes longer to build another factory than it takes to get
            # the goal, we're certainly done:
            if remaining_time_with_current_productivity < time_to_next_factory:
                return time_spent_so_far + remaining_time_with_current_productivity

            remaining_time_with_next_factory = time_to_next_factory + problem.x / (productivity_f + problem.f)

            if remaining_time_with_next_factory < remaining_time_with_current_productivity:
                #print("(productivity_f) = %1.5f"%(productivity_f))
                #print("(time_spent_so_far) = %1.5f"%(time_spent_so_far))
                #print("(time_to_next_factory) = %1.5f"%(time_to_next_factory))
                #print("(remaining_time_with_current_productivity) = %1.5f"%(remaining_time_with_current_productivity))
                #qprint("(remaining_time_with_next_factory) = %1.5f"%(remaining_time_with_next_factory))
                time_spent_so_far += time_to_next_factory
                productivity_f    += problem.f
                continue
            else:
                return time_spent_so_far + remaining_time_with_current_productivity

    def str_solution(self, solution):
        return "%1.7f"%(solution)

if __name__ == "__main__":
    import sys
    a = Codejam_2014_B()
    a.run(sys.argv[1])
