file = open('C-small-attempt4.in', 'r')
output = open('output', 'w')

T = file.readline()

def topostal(order):
    result = ''
    for o in order:
        result = result + str(postal[o])
    return int(result)

def minindex(postal):
    i = 0
    min = postal[0]
    for j in range(len(postal)):
        if postal[j] < min:
            min = postal[j]
            i = j
    return i

def topos(i):
    return postal[i]

def ischildof(f, child, flights, visithelp):
    if f in visithelp:
        return False
    visithelp.append(f)
    for l in flights[f]:
        if l == child:
            return True
        if ischildof(l, child, flights, visithelp):
            return True
    return False
    
def isbetterthansibling(i, flights, postal, N, M, p, pp):
    if pp == -1:
        return True
    for f in flights[pp]:
        if topos(f)>topos(p) and topos(f)<topos(i):
            if ischildof(f, i, flights, [p]):
                return False
    return True

def dfs(i, flights, postal, N, M, p, pp, visited):
    if not isbetterthansibling(i, flights, postal, N, M, p, pp):
        print(i, p, pp)
        return []
    visited.append(i)
    result = [i]
    for f in flights[i]:
        if f not in visited:
            result.extend(dfs(f, flights, postal, N, M, i, p, visited))
    return result    

for x in range(1, int(T)+1):
    visited = []
    [N, M] = list(map(lambda x: int(x), file.readline().replace('\n', '').split(' ')))
    
    postal = []
    for i in range(N):
        postal.append(int(file.readline().replace('\n', '')))
                
    flights1 = []
    for i in range(M):
        flights1.append(list(map(lambda x: int(x)-1, file.readline().replace('\n', '').split(' '))))
        
    flights = [[] for _ in range(N)]
    for flight in flights1:
        if not flight[0] == flight[1]:
            flights[flight[0]].append(flight[1])
            flights[flight[1]].append(flight[0])
    
    flights = list(map(lambda x: sorted(x, key=topos), flights))
    
    order = dfs(minindex(postal), flights, postal, N, M, -1, -1, visited)
    print('v',visited)
    
    answer = str(topostal(order))
            
    solution = 'Case #' + str(x) + ': ' + answer + '\n'
    if x == int(T):
        solution.replace('\n', '')
    output.write(solution)
    print(solution)