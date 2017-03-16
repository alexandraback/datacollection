fin= open('Bin')
fout= open('Bout', 'w')
N=int(fin.readline())

#fstring= fin.read()
fsout=''


for i in range(N):
    fsout='Case #'+ str(i+1) +": "
    levels=int(fin.readline())
    ld=[]
    for i in range(levels):
        ld.append( tuple(int(z) for z in ((fin.readline()).split())))
    x2, y2 = zip(*ld)
    x=list(x2)
    y=list(y2)
  
    stars=0
    steps=0

    fail=0
    while stars < levels*2:
        a=y.index(min(y))
        b=x.index(min(x))
        if y[a] <= stars:
            if x[a]<=stars:
                steps+=1
                stars+=2
                y[a]=9999
                x[a]=9999
            else:
                steps+=1
                stars+=1
                y[a]=9999
                x[a]=9999
        elif x[b]<=stars:
            poop=[]
            swoop=[]
            for r in range(len(x)):
                if x[r]<=stars:
                    poop.append(r)
            for l in poop:
                swoop.append(y[l])
            c=y.index(max(swoop))
            x[c]=9999
            steps+=1
            stars+=1
            
        else:
            fail=1
            break

    if fail==1:
        fsout= fsout+"Too Bad" + "\n"
    else:    
        fsout= fsout+str(steps) + "\n"
        

    fout.write(fsout)

fin.close()
fout.close()
    

