file=open("B-small-attempt2.in","r")
file_out=open("B.out","wr")

case_n=file.readline()

for x in xrange(int(case_n)):
    case_id=x+1
    case_vn=int(file.readline())
    case_vn=2*case_vn-1
    count=0
    values=[]
    dict={}
    while count<case_vn:
        line=file.readline().strip()
        nums=line.split(" ")
        for n in nums:
            if n not in dict.keys():
                dict[n]=1
            else:
                dict[n]+=1
        count+=1
    result=[]
    for key in dict.keys():
        if dict[key]%2!=0:
            result.append(int(key))
    result.sort()
    for index in xrange(len(result)):
        result[index]=str(result[index])

    fs= " ".join(result)
    file_out.writelines("Case #"+str(case_id)+": "+fs+"\n")


