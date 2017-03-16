#!py -3

def main():
    """
    The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a string S.
    
    Small dataset
        1 = length of S = 15.
    Large dataset
        1 = length of S = 1000.
    """
    
    for i in range(int(input())):
        s = input().strip()
        print("Case #%d:" % (i+1), solve(s))


def solve(s):
    # Identify all letters which are >= the letters before them.
    # If it is not bigger than the letters before, then put it in the back.
    
    best = '!' #need smaller than all letters
    result = ''
    for c in s:
        if c >= best:
            best = c
            result = c + result
        else:
            result += c
    
    return result

    
main()

