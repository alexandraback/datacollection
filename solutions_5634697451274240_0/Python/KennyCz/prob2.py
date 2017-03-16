import sys
from sets import Set



def answer(stck):
    stck += '+'
    cnt = 0
    for i in range(len(stck)-1):
        if stck[i] != stck[i+1]:
            cnt+=1
    return cnt



if __name__ == "__main__":

    T = int(sys.stdin.next())
    queries = []
    for i in range(T):
        queries.append(str(sys.stdin.next()).rstrip())
    for i,n in enumerate(queries):
        print "".join(["Case #", str(i+1), ": ", str(answer(n))])

