inputfile=open("A-small-attempt0.in","r")
outputfile=open("outputfile.txt","w")

def last_number(seed):
    if seed == 0:
        return ("INSOMNIA")
    else:
        newlist=[]
        counter=1
        latest_number=0
        while True:
            latest_number=counter*seed
            seedstring = str(latest_number)
            for element in seedstring:
                if element not in newlist:
                    newlist.append(element)
            if len(newlist)==10:
                return latest_number
                break
            else:
                counter+=1
              
linenumber=0
for line in inputfile:
    linenumber+=1
    if linenumber==1:
        pass
    else:
        outputfile.write("Case #"+str(linenumber-1)+": "+str(last_number(int(line.strip())))+"\n")

inputfile.close()
outputfile.close()
