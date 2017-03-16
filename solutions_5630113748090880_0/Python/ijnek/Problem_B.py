file_object = open('B-small-attempt0 (1).in','r')
file_object2 = open('output.txt','w')

t = int(file_object.readline().rstrip('\n'))

for i in range(t):
    list = [0 for _ in range(2502)]
    lostPieceList = []
    n = int(file_object.readline().rstrip('\n'))
    for _ in range(2*n-1):
        line = map(int,file_object.readline().rstrip('\n').split())
        for item in line:
            list[item] += 1
    for _ in range(2502):
        if list[_]%2:
            lostPieceList.append(_)
    lostPieceList.sort()

    line = "Case #{}: {}\n".format(i+1,' '.join([str(a) for a in lostPieceList]))
    file_object2.write(line)