import sys
infile=open(sys.argv[1])
#contents=infile.read()
#print contents
line=infile.readline()
numofcases=int(line)
print numofcases,"cases"

count=0
outfile=open("out.txt","w")
for i in range(numofcases):
    count+=1
    outfile.write("Case #"+str(count)+":\n")
    line=infile.readline()
    print line
    numbers=[]
    for n in line.split():
        numbers.append(int(n))
    numofnum=numbers.pop(0)
    print numofnum
    print numbers
    sum={}
    for n in numbers:
        sum[n]=[n,]
    found=False
    for i in range(len(numbers)):
        #for i in sum.keys():
         #   print i,sum[i]
        for j in numbers:
            if found:
                break
            newsum={}
            for val in sum.keys():
                if j not in sum[val]:
                    if j+val in sum.keys():
                         l1=sum[val][:]
                         l1.append(j)
                         if set(sum[j+val]) != set(l1):
                             str1=""
                             for i in l1:
                                 str1+=str(i)+" "
                             str1+="\n"
                             str2=""
                             for i in sum[j+val]:
                                 str2+=str(i)+" "
                             str2+="\n"
                             outfile.write(str1)
                             outfile.write(str2)
                             print l1
                             print sum[j+val]
                             found=True
                             break
                    else:
                        if j+val in newsum.keys():
                            l1=sum[val][:]
                            l1.append(j)
                            if set(newsum[j+val]) != set(l1):
                                print l1
                                print newsum[j+val]
                                str1=""
                                for i in l1:
                                    str1+=str(i)+" "
                                    str1+="\n"
                                    str2=""
                                for i in newsum[j+val]:
                                    str2+=str(i)+" "
                                    str2+="\n"
                                outfile.write(str1)
                                outfile.write(str2)
                                found=True
                                break
                        else:
                            newsum[val+j]=sum[val][:]
                            newsum[val+j].append(j)

            if found:
                break
            sum.update(newsum)
    if not found:
        outfile.write("Impossible"+"\n")
        print "impossible"

outfile.close()
    

