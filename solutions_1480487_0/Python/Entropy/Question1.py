
count = 1
for line in open("A-small-attempt6.in","rU").readlines()[1:]:
    line = line.strip().split(" ")
    cont = float(line[0])
    line = line[1:]
    total = 0.0
    for i in line:
        total += float(i)
    result = "Case #"+str(count)+":"
    low = 101
    for i in line:
        i = float(i)
        num = (float(100*(((((total/cont)-i)/(total/cont))+1.0)*((total/cont)/total))  ))
        result += (" " + str(num))
    print (result)
    count +=1 
