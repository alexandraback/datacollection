def presmetaj(n,ns):
    for i in range(int(n)):
        endpoints = presmetajr(i+1,ns,[])
        for j in range(len(endpoints)):
            if endpoints.count(endpoints[j]) > 1:
                return "Yes"
    return "No"

def presmetajr(n,mapa,endpoints):
    nInMap = False
    for i in range(len(mapa)):
        if mapa[i][0] == n:
            nInMap = True
            break
    if nInMap == False:
        return []
    else:
        for i in range(len(mapa)):
            if mapa[i][0] == n:
                endpoints.append(mapa[i][1])
                endpoints = endpoints + presmetajr(mapa[i][1],mapa,[])
        return endpoints
        
f = open('input', 'rU')
f2 = open('output', 'w')
r = ''
for i in range(int(f.readline())):
    n = f.readline()
    ns = []
    print
    for j in range(int(n)):
        directions = [int(x) for x in f.readline().split()]
        for z in range(int(directions[0])):
            ns.append([j+1,directions[z+1]])
    r+='Case #' + str(i+1) + ': ' + str(presmetaj(n,ns)) + '\n'
f2.write(r)
f.close()
f2.close()