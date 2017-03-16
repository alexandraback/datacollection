file_object = open('A-large (2).in','r')
file_object2 = open('output.txt','w')

t = int(file_object.readline().rstrip('\n'))

for i in range(t):
    s = file_object.readline().rstrip('\n')
    s = list(s)
    listFront = []
    index = len(s)

    while index !=0:
        mx = max(s[0:index])
        index = len(s[0:index])-1-s[0:index][::-1].index(mx)
        listFront.append(s.pop(index))
    #x,y = map(int,file_object.readline().rstrip('\n').split())


    output = "Case #{}: {}{}\n".format(i+1,''.join(listFront),''.join(s))
    file_object2.write(output)