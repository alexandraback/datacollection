def cheat(naomi, ken):
    nscore = 0

    while len(naomi) > 0:
        while  len(ken) >0 and (max(ken) > max(naomi) or min(naomi) < min(ken)):

            if max(ken) > max(naomi):
                ken.discard(max(ken))
                naomi.discard(min(naomi))
                #print "+1 for ken"


            if len(ken) >0 and min(naomi) < min(ken):
                naomi.discard(min(naomi))
                ken.discard(max(ken))
                #print "+1 for ken (type2)"

        if len(ken) >0 and max(naomi) > max(ken): #should be!
            naomi.discard(max(naomi))
            ken.discard(max(ken))
            #print "+1 for naomi"
            nscore +=1 



    return nscore

def fair(naomi,ken):

    nscore = 0

    naomi.sort()
    ken.sort()

    while len(naomi) > 0:
        nplay = naomi.pop(0)
        #print nplay
        for x in range(len(ken)):
            if ken[x] > nplay:
                ken.pop(x)
                break
        if len(ken) != len(naomi):
            ken.pop(0)
            nscore +=1

            #print naomi, ken

    return nscore


f = open('input.in', 'r')
data = f.read().split('\n')
#print data

length = int(data[0])
for x in range(length):
    naomi = map(float, data[2 + 3*x].split(" "))
    ken = map(float, data[3+ 3*x].split(" "))
    print "Case #%d: %d %d" % (x+1, cheat(set(naomi), set(ken)) , fair(naomi,ken))
