inputfile=open("D-small-attempt2.in","r")
outputfile=open("outputfile.txt","w")

#Just need to consider whether the first k blocks have any G.
#Should be possible because k=S and there should be just enough
#graduate students to search through the first k blocks.
def small_solver(k,c):
    returnstring=""
    for i in range(1,k+1):
        returnstring+=(str(i)+" ")
    return returnstring

linenumber=0
for line in inputfile:
    linenumber+=1
    if linenumber == 1:
        pass
    else:
        values = line.strip().split(" ")
        k=values[0]
        c=values[1]
        ans=small_solver(int(k),int(c))
        outputfile.write("Case #"+str(linenumber-1)+": "+ans+"\n")
inputfile.close()
outputfile.close()
