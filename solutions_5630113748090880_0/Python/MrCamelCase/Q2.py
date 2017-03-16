inp = open("B-small-attempt1.in.txt").readlines()
oup = open("Q2OUT.txt","w")
limit = int(inp[0].rstrip())
qn = 0
index = 1
while limit>qn:
    qn+=1
    N = int(inp[index].rstrip())
    rows = [[int(a) for  a in i.rstrip().split()] for i in inp[index+1:index+(2*N)]]
    #print(rows)
    dic = {}
    for row in rows:
        for soldier in row:
            if soldier not in dic.keys():
                dic[soldier] = 0
            dic[soldier] += 1
    odds = []
    for item in dic:
        if dic[item]%2 != 0:
            odds.append(item)
    #print(odds)
    answer = list(sorted(odds))
        
    sanswer = (" ").join([str(i) for i in answer])
    #print(sanswer)
    oup.write("Case #%s: %s"%(str(qn),sanswer))
    if qn != limit:
              oup.write('\n')
    index += (2*N)
oup.close()
