import sys
from sets import Set



def answer(query):
    ans = []
    while 'Z' in query:
        query.remove('Z')
        query.remove('E')
        query.remove('R')
        query.remove('O')
        ans.append(0)
    while 'W' in query:
        query.remove('T')
        query.remove('W')
        query.remove('O')
        ans.append(2)
    while 'U' in query:
        query.remove('F')
        query.remove('O')
        query.remove('U')
        query.remove('R')
        ans.append(4)
    while 'X' in query:
        query.remove('S')
        query.remove('I')
        query.remove('X')
        ans.append(6)
    while 'G' in query:
        query.remove('E')
        query.remove('I')
        query.remove('G')
        query.remove('H')
        query.remove('T')
        ans.append(8)
    while 'O' in query:
        query.remove('O')
        query.remove('N')
        query.remove('E')
        ans.append(1)
    while 'R' in query:
        query.remove('T')
        query.remove('H')
        query.remove('R')
        query.remove('E')
        query.remove('E')
        ans.append(3)
    while 'F' in query:
        query.remove('F')
        query.remove('I')
        query.remove('V')
        query.remove('E')
        ans.append(5)
    while 'V' in query:
        query.remove('S')
        query.remove('E')
        query.remove('V')
        query.remove('E')
        query.remove('N')
        ans.append(7)
    while 'N' in query:
        query.remove('N')
        query.remove('I')
        query.remove('N')
        query.remove('E')
        ans.append(9)
    return "".join(map(str,sorted(ans)))


if __name__ == "__main__":

    T = int(sys.stdin.next())
    queries = []
    for i in range(T):
        queries.append(list(sys.stdin.next()))
    for i,st in enumerate(queries):
        print "".join(["Case #", str(i+1), ": ", answer(st)])
       
    
