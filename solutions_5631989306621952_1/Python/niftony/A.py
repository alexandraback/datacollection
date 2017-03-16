file=open("A-large.in","r")
file_out=open("A.out","wr")

case_n=file.readline()

for x in xrange(int(case_n)):
    case_id=x+1
    case_v=file.readline()
    result=case_v[0]

    for index in xrange(1,len(case_v)):
        if case_v[index]<result[0]:
            result=result+case_v[index]
        else:
            result=case_v[index]+result
    file_out.writelines("Case #"+str(case_id)+": "+result+"")
