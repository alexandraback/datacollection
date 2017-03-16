if __name__ == '__main__':
    file_in=open('D-small-attempt0.in','r')
    file_out=open('output.out','w')
    loop = file_in.readline()

    
    
    for a in range(int(loop)):
        
        N=int(file_in.readline())

        naomi=map(float,file_in.readline().split(' '))
        ken=map(float,file_in.readline().split(' '))

        war=0
        decepit=0

        naomi_war=naomi[:]
        ken_war=ken[:]
        naomi_war.sort(reverse=True)



        for i in range(N):
            res=[idx for idx,val in enumerate(ken_war) if val>naomi_war[i]]
            res.sort()
            if res==[]:
                war+=1
                val, idx = min((val, idx) for (idx, val) in enumerate(ken_war))
                del ken_war[idx]
            else:
                del ken_war[res[0]]


        naomi_decept=naomi[:]
        ken_decept=ken[:]
        naomi_decept.sort(reverse=True)
        ken_decept.sort(reverse=True)

        for i in range(N):
            if naomi_decept[0]>ken_decept[0]:
                decepit+=1
                del naomi_decept[0]
                del ken_decept[0]
            else:
                del naomi_decept[-1]
                del ken_decept[0]

        file_out.write("Case #%d: %d %d\n"%(a+1,decepit,war))



    file_in.close()
    file_out.close()


