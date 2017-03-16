
from CodeJamHelper import CodeJamHelper
import math

def main():
    h = CodeJamHelper("C-small-attempt2")    
    
    n = h.nextInt()

    for x in range(n):
        h.output(process(h.nextLineOfInts()))

def process(nmk):
    n = nmk[0]
    m = nmk[1]
    k = nmk[2]
    smaller = nmk[:2]
    smaller.sort()
    larger = smaller[1]

    smaller = smaller[0]
    return shrink(smaller, larger, k)
    
def hardcode(s, l,k):
    if k < 5:
        return True, k
    if s == 1 or l == 1:
        return True, k
    return False, k

def shrink(s, l, k):
    h, v = hardcode(s, l,k)
    if(h):
        return v
    discs = s * 2 + l * 2 - 4
    enclosed = s * l
    if enclosed == k: #whole thing
        return discs
    discs -= 1
    enclosed -=1
    if enclosed == k: #one corner
        return discs
    
    discs -= 1
    enclosed -=1
    if enclosed == k: #two  corner
        return discs

    smaller = s
    larger = l
    #iterate
    while enclosed != k:
        discs -= 1
        enclosed -=1
        if enclosed == k: #3rd corner
            return discs
        
        discs -= 1
        enclosed -=1
        if enclosed == k: #4rd corner
            return discs
        
        for x in range(smaller - 2):
            enclosed -=1
            if enclosed == k: #scoot
                return discs
        larger = larger - 1
        if(smaller > larger):
            temp = smaller
            smaller = larger
            larger = temp
    return "impossible"

    
if __name__ == "__main__":
    main()