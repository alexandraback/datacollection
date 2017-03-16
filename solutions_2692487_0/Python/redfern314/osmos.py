def osmos(mote,other,moves):
    if other == []:
        return moves
    if mote > other[0]:
        return osmos(mote+other[0],other[1:],moves)

    # remove mote
    newotherremove = other[:-1]
    #newotherremove.sort()
    remove = osmos(mote,newotherremove,moves+1)

    # add mote
    if mote>1:
        newotheradd = list(other)
        newotheradd.append(mote-1)
        newotheradd.sort()
        add = osmos(mote,newotheradd,moves+1)
    else:
        add = 999999

    if add<remove:
        return add
    else:
        return remove

tests = int(raw_input())
i = 0
out = open('output.txt','w')

while i<tests:
    i+=1
    mote,num=raw_input().strip().split()
    mote = int(mote)
    num = int(num)
    other = [int(x) for x in raw_input().strip().split()]
    other.sort()
    out.write("Case #"+str(i)+": "+str(osmos(mote,other,0))+'\n')



