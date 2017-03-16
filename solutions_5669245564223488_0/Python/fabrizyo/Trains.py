__author__ = 'fabrizio'

def compress(cs):
    for i in range(len(cs)):
        res=""+cs[i][0]
        for j in range(1,len(cs[i])):
            if cs[i][j]!=cs[i][j-1]:
                res+=cs[i][j]
        cs[i]=res

MOD=1000000007
facts=[1]*101
for i in range(1,len(facts)):
    facts[i]=(i*facts[i-1])%MOD


with open("input.txt") as fin:
    with open("output.txt","w") as fout:
        T=int(fin.readline().strip())
        for t in range(1,T+1):
            N=int(fin.readline().strip())
            cars=fin.readline().strip().split()
            compress(cars)

            singolo_car={}
            for car in cars:
                if len(car)==1:
                    if car not in singolo_car:
                        singolo_car[car]=0
                    singolo_car[car]+=1

            mult_singolo=1
            for car in cars:
                if len(car)>1:
                    if car[0] in singolo_car:
                        mult_singolo*=facts[singolo_car[car[0]]]
                        del singolo_car[car[0]]

                    if car[-1] in singolo_car:
                        mult_singolo*=facts[singolo_car[car[-1]]]
                        del singolo_car[car[-1]]

            #elimino i singoli gia usati
            for i in range(len(cars)):
                if len(cars[i])==1:
                    if cars[i] not in singolo_car:
                        cars[i]=None

            for singolo in singolo_car:
                mult_singolo*=facts[singolo_car[singolo]]

            #attacco i possibili da attaccare e verifico se sia possibile
            for i in range(len(cars)):
                if cars[i]:
                    for j in range(len(cars)):
                        if i!=j:
                            if cars[j]:
                                if cars[j][0]==cars[i][-1]:
                                    cars[i]+=cars[j]
                                    cars[j]=None

            #verifico se sia possibile per il singolo
            possible=True
            for car in cars:
                if car:
                    used=set()
                    used.add(car[0])
                    for i in range(1,len(car)):
                        if car[i]!=car[i-1]:
                            if car[i] in used:
                                possible=False
                            used.add(car[i])

            #possibile con tanti
            for i in range(len(cars)):
                if cars[i]:
                    for j in range(i+1,len(cars)):
                        if cars[j]:
                            for ch in cars[i]:
                                if ch in cars[j]:
                                    possible=False

            res=0
            if possible:
                tot=reduce(lambda x,y:x+(1 if y else 0),cars,0)
                res=mult_singolo*facts[tot]
                res%=MOD

            fout.write("Case #"+str(t)+": "+str(res)+"\n")

