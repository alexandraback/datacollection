import itertools
import re

if __name__ == "__main__":
    T = int(input())

    for i in range(1,T+1):
        S = input()
        zero = S.count("Z")
        six = S.count("X")
        seven = S.count("S")-six
        five = S.count("V")-seven
        four = S.count("F")-five
        three = S.count("R")-four-zero
        eight = S.count("G")
        two = S.count("W")
        one = S.count("O")-two-four-zero
        nine = S.count("I")-five-six-eight
        
        digits = [1,]*one + [2,]*two + [3,]*three + [4,]*four + [5,]*five +\
                 [6,]*six + [7,]*seven + [8,]*eight + [9,]*nine + [0,]*zero

        res = "".join( str(d) for d in sorted(digits) )
        print("Case #%i: %s" % (i,res))
