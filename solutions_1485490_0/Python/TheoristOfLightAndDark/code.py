f = open("in.txt","r")
g = open("out.txt","w")

su = 0
box =[]
toy =[]
max2= -1

def recu(i,ri,su,uiu):
    global max2
    ui = 0
    if i == len(box)-1:
        ex = 0
        toy[ri][1]-=uiu
        for iii in range(ri,m):
            if toy[iii][0]==box[i][0]:
                if toy[iii][1]<box[i][1]:
                    ex += toy[iii][1]
                    box[i][1] -= toy[iii][1]
                else:
                    ex += box[i][1]
                    box[i][1] = 0
        if su+ex >max2:
            max2=su+ex
        box[i][1]+=ex
        toy[ri][1]+=uiu
    else:
        toy[ri][1] -= uiu
        for iii in range(ri,m):
            ex = 0
            for iji in range(ri,iii):
                if toy[iji][0]==box[i][0]:
                    if toy[iji][1]<box[i][1]:
                        ex += toy[iji][1]
                        box[i][1] -= toy[iji][1]
                    else:
                        ex += box[i][1]
                        box[i][1] = 0
            ui = 0
            if toy[iii][0]==box[i][0]:
                    if toy[iii][1]<box[i][1]:
                        ex += toy[iii][1]
                        box[i][1] -= toy[iii][1]
                        ui = toy[iii][1]
                    else:
                        ex += box[i][1]
                        box[i][1] = 0
                        ui = box[i][1]
            recu(i+1,iii,su+ex,ui)
            box[i][1]+=ex
        toy[ri][1]+=uiu

tcase = int(f.readline())+1
for t in range(1,tcase):
    st = f.readline().split()
    n = int(st[0])
    m = int(st[1])
    box = []
    toy = []
    su = 0
    max2 = -1
    st = f.readline().split()
    for i in range(n):
        box.append([int(st[2*i+1]),int(st[2*i])])
    st = f.readline().split()
    for i in range(m):
        toy.append([int(st[2*i+1]),int(st[2*i])])
    max2 = -1
    su = 0
    recu(0,0,0,0)
    g.write("Case #"+str(t)+": "+str(max2)+"\n")
f.close()
g.close()