inp = open("A-small-attempt0.in.txt").readlines()
oup = open("Q1OUT.txt","w")
limit = int(inp[0].rstrip())
qn = 0

for i in inp[1:]:
    qn+=1
    answer = ""
    #CODE HERE
    string = i.rstrip()
    array = [i for i in string]
    for letter in array:
        if answer =="":
            answer+=letter
        else:
            if letter>=answer[0]:
                answer = letter+answer
            else:
                answer+=letter
        #print(answer)
    
    oup.write("Case #%s: %s"%(str(qn),str(answer)))
    if qn!= limit:
        oup.write("\n")



oup.close()
