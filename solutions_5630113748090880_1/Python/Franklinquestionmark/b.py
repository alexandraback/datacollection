#!py -3

def main():
    """
     The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with an integer N, followed by 2*N-1 lines of N integers each, representing the lists you have, as described in the statement. It is guaranteed that these lists represent all but one of the rows and columns from a valid grid, as described in the statement. 
    """
    
    '''
    Small: 
        2 <= N <= 10
    Large:
        2 <= N <= 50
    
    '''
    
    
    for i in range(int(input())):
        
        ## INPUT ##
        n = int(input())
        s = [tuple(int(x) for x in input().strip().split())
                for _ in range(n*2-1)]
        
        ## OUTPUT ##
        
        ans = ' '.join(map(str, solve(s)))
        
        ## PRINT ##

        print("Case #%d:" % (i+1), ans)
#

from collections import Counter
from itertools import *
def solve(s):
    # Herp derp just count the ones that aren't on two sheets.
    
    ctr = Counter(chain.from_iterable(s))
    return sorted(x for x, c in ctr.items() if c%2 == 1)
    
    


# # return: Tuple[int]
# #         The missing sheet.
# def solve(s):
    # # Topological sorting?
    
    # # There is a unique smallest and largest.
    # s.sort()
    # # There. Smallest soldier should be on the first two sheets.
    # if s[0][0] != s[1][0]:
        # # If not, we found the missing sheet.
        # pass
    # # The next smallest soldier is
        # # min(s[0][1], s[1][1])
        # # possibly both.
    
    
    # # Reversed:
    # s1 = sorted(map(lambda t: t[::-1], s), reverse=True)
    
    
    # return 


def less(t, u):
    return all(ti < ui for ti, ui in zip(t,u))


main()

