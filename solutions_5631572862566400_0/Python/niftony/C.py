file=open("C-small-attempt4.in","r")
file_out=open("C.out","wr")

case_n=file.readline()

for x in xrange(int(case_n)):
    case_id=x+1
    case_vn=int(file.readline())
    vs=file.readline().split(" ")

    for index in xrange(len(vs)):
        vs[index]=int(vs[index])

    possible=[]
    pairs=[]
    if case_id==54:
        print vs
    # all student
    for index in xrange(1,case_vn+1):
        already=[]
        next_one=vs[index-1]
        already.append(index)
        while next_one not in already:
            already.append(next_one)
            next_one=vs[next_one-1]
        last_id=already[-1]
        while len(already)>1:
            if not (vs[last_id-1]==already[-2] or vs[last_id-1] ==already[0] ):
                already.pop()
                last_id=already[-1]
            else:
                break

        # print already,len(already)
        # find the last one
        for index in xrange(1,case_vn+1):
            if index not in already:
                if len(already)==0:
                    already.append(index)
                    continue
                if len(already)==1:
                    continue
                if vs[index-1]==already[-1] and vs[already[-1]-1]==already[-2] :
                    already.append(index)

        if len(already)==2:
            pairs.append(already)

        result=len(already)
        for pair in pairs:
            common=False
            for n in pair:
                if n in already:
                    common=True
            if not common:
                already=already+pair
                result+=2

        possible.append(result)

    file_out.writelines("Case #"+str(case_id)+": "+str(max(possible))+"\n")

