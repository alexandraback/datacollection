fin= open('A-small-attempt0.in')
#fin= open('A-large.in')
fout= open('Aout', 'w')
N=int(fin.readline())

#fstring= fin.read()
fsout=''

for i in range(N):
    flout=(fin.readline()).split()
    fsout='Case #'+ str(i+1) +": "
    flout1=[int(z) for z in flout]
    
    sum1= sum(flout1[1:])
    
    a=flout1.pop(0)
    boy=list(flout1)
    popo=[0 for j in flout1]
    suma=1
    slooo=[]
    while suma >0:
        lol= min(flout1)
        b=boy.index(lol)
        slooo.append(boy.pop(b))
        if len(boy)>0:
            lol1=min(boy)
        else:
            lol1=9999999999999
        

        if suma> len(slooo)*(lol1-lol)/sum1:
            suma= suma- len(slooo)*(lol1-lol)/sum1
            for i in range(len(flout1)):
                if flout1[i]<lol1:
                    flout1[i]=lol1
                    popo[i]+=(lol1-lol)/sum1
        else:
            for i in range(len(flout1)):
                if flout1[i]<lol1:
                    popo[i]+=suma/len(slooo)
            suma=0

         
    for j in range(a):
        popo[j]=100*popo[j]   
        fsout=fsout+ format(popo[j], '.6f')+' '

    fsout=fsout[:-1]
    fsout=fsout+"\n"
        
            
    fout.write(fsout)

fin.close()
fout.close()
    

