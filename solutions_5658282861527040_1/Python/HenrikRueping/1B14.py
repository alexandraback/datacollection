import math
#f = open('B-small-attempt0.in', 'r')
f = open('B-large.in', 'r')
#f = open('B-sample.in', 'r')
outpu=open('output.txt','w')
cases = int(f.readline())
for case in range(cases):
    [A,B,K]=[int(X)-1 for X in f.readline().split(" ")]
    #K=K-1
    #print([A,B,K])
    maxlen =max([A,B,K])
    maxlen =1 if maxlen==0 else int(math.log(maxlen,2))+1
    #print(maxlen)
    p={}
    p[(0,0,0)]=1
    ones=0
    for i in range(maxlen+1):
        #print(p)
        lones=ones
        ones=(ones<<1)+1
        #print("ones,lones",ones,lones)
        #p[(ones,ones,ones)]=4**(i+1)
        #[fK,fA,fB]=[(K>>i)%2,(A>>i)%2,(B>>i)%2]
        ##print('f:',fA,fB,fK)
        [tK,tA,tB]=[K & ones,A&ones,B&ones]
        #print('t:',tA,tB,tK)
        [ltK,ltA,ltB]=[K & lones,A&lones,B&lones]
        #print('ltc:',ltA,ltB,ltK)
        for [ck,ca,cb] in [[tK,tA,tB],[tK,tA,ones],[tK,ones,tB],[tK,ones,ones],
                           [ones,tA,tB],[ones,tA,ones],[ones,ones,tB],[ones,ones,ones]]:
            #print('cur',ca,cb,ck)
            #print(p)
            [fK,fA,fB]=[(ck>>i)%2,(ca>>i)%2,(cb>>i)%2]
            [ltcK,ltcA,ltcB]=[ck & lones,ca&lones,cb&lones]
            if fK==0:
                p[(ca,cb,ck)]=p[(lones if fA==1 else ltcA,lones if fB==1 else ltcB,ltcK)]#case 0,0,0
                if fA==1:
                    p[(ca,cb,ck)]+=p[(ltcA,lones if fB==1 else ltcB,ltcK)]#case 1,0,0
                if fB==1:
                    p[(ca,cb,ck)]+=p[(lones if fA==1 else ltcA,ltcB,ltcK)]#case 0,1,0
                #case 1,1,0 is forbidden
            else:
                p[(ca,cb,ck)]=p[(lones if fA==1 else ltcA,lones if fB==1 else ltcB,lones)]
                if fA==1:
                    p[(ca,cb,ck)]+=p[(ltcA,lones if fB==1 else ltcB,lones)]#case 1,0,0
                if fB==1:
                    p[(ca,cb,ck)]+=p[(lones if fA==1 else ltcA,ltcB,lones)]#case 0,1,0
                if fA==1 and fB==1:
                    p[(ca,cb,ck)]+=p[(ltcA,ltcB,ltcK)]#case 1,1,1
    result  = str(p[(A,B,K)])
    #print('Case #'+ str(case+1)+": "+ result)
    outpu.write('Case #'+ str(case+1)+": "+ result+"\n")
f.close()
outpu.close()
