#!/usr/bin/python3

def is_fair(n):
    s = str(n)
    l = len(s) // 2
    return s[:l]==s[:-l-1:-1]


def bruteforce(N):
    """
    Return all the palindromic square numbers below N
    """
    n = 1
    s = 1
    res = [1]

    while s<N:
        s += 2*n + 1
        n += 1

        # Check if n and s are fair
        if is_fair(n) and is_fair(s):
            res.append(s)
    return res



CACHE = bruteforce(1+10**14)
# Nice for debugging, but I am sure it will be not really fair to use it in the final version :)
# Anyway, it takes 12 seconds to obtain it in my machine
# CACHE = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

def count_elements(A, B):
    return sum(A<=x<=B for x in CACHE)




def solve(fd):
    
    T = int(fd.readline().strip())
    for c in range(T):
        A, B = (int(x) for x in fd.readline().strip().split())
        print("Case #" + str(c+1) + ": " + str(count_elements(A, B)))


if __name__ == "__main__":
    import sys
    
    fd = open(sys.argv[1], "r")
    solve(fd)
    fd.close()

            

