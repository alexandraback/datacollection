import string

in_file = open("a-small.in","r");
out_file = open("a-small.out","w");

case_num = 0;
case_max = 0;

for line in in_file:
    if (case_max == 0):
        case_max = int(line)
        case_num = 1
        continue
    
    split_line = line.split()
    
    count = int(split_line[0])
    judge = {}
    total_judge = 0
    answer = []
    
    judge_sorted = []
    
    
    for i in range(1,count+1):
        tmp = int(split_line[i])
        judge[i-1] = tmp
        total_judge += tmp
        
    print judge
    judge_sorted = sorted(judge.items(), key = lambda t:t[1])
    print judge_sorted
    print judge_sorted[0][0]
    print judge_sorted[0][1]
    for i in range(0,count):
        if (judge_sorted[0][1] + total_judge < judge[i]):
            answer = 0
            continue
        elif (judge[i] == judge_sorted[1] and judge_sorted[1] + total_judge < judge[i]):
            answer = 0
            continue
        pass
        
        self_pass = 0;
        amount = total_judge
        votes = [0] * count
        #print len(judge_sorted)
        for j in range(1,count):
            #print j
            diff = judge_sorted[j][1] - judge_sorted[j-1][1]
            if (diff == 0):
                continue
            if (amount < diff*j):
                diff = float(amount) / float(j)
                amount = 0
            for k in range(0,j):
                votes[k] += diff
            if (amount == 0):
                break
            amount -= diff*j
            
            
            
            
    
    for x in range(0,count):
        if (amount > 0):
            votes[x] += float(amount) / float(count)
        judge_sorted[x] = tuple([judge_sorted[x][0], str(100.0 * float(votes[x]) / float(total_judge))])
    
    result_set = sorted(judge_sorted, key=lambda t: t[0])
    
    for x in range(0,count):
        result_set[x] = result_set[x][1]
    
    result = ' '.join(result_set)
    
    print result
    out_file.write("Case #"+str(case_num)+": "+str(result)+"\n")
    case_num += 1
