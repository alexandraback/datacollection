import sys
from sets import Set



def answer(K, C, S):
    lst = [ range(K)[i : i + C] for i in range(0, K, C) ]
    nums = [1+digstonum(x, K) for x in lst]
    if len(nums) > S:
        return "IMPOSSIBLE"
    else:
        return " ".join(map(str,nums))

def answer_easy(K, C, S):
    return " ".join(map(str,range(1, K+1)))

def digstonum(digs, base):
    res = 0
    for num in digs:
        res *= base
        res += num
    return res


if __name__ == "__main__":

    T = int(sys.stdin.next())
    queries = []
    for i in range(T):
        queries.append(map(int, sys.stdin.next().split(' ')))
    for i,qr in enumerate(queries):
        print "".join(["Case #", str(i+1), ": ", str(answer(*qr))])

