f = open('Google Lawnmower Large.in','r')
g = open('Google Lawnmower Large.out','w')

def Google_print(filename,answers):
    for i in range(len(answers)):
        filename.write("Case #%s: %s\n" % (str(i+1),answers[i]))
        print "Case #%s: %s" % (str(i+1),answers[i])
    return

def is_possible(a,x,y):
    row = a[x]
    column = [a[r][y] for r in range(len(a))]
    v = a[x][y]
    check1 = [p for p in row if p > v]
    check2 = [p for p in column if p > v]
    if not check1 or not check2:
        return True
    else:
        return False

def parse(s):
    answer = []
    s = s.split('\n')
    for i in s:
        row = i.split(' ')
        row = [int(x) for x in row]
        answer.append(row)
    return answer

def lawnmower(a,N,M):
    for i in range(N):
        for j in range(M):
            if not is_possible(a,i,j):
                return "NO"
    return "YES"

cases = int(f.readline())
answer = []
for i in range(cases):
    N,M = f.readline().rstrip().split(' ')
    N = int(N)
    M = int(M)
    a = []
    for row in range(N):
        r = f.readline().rstrip().split(' ')
        r = [int(p) for p in r]
        a.append(r)
    answer.append(lawnmower(a,N,M))
Google_print(g,answer)
g.close()
f.close()


    


                
