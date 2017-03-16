import sys;
inFile = open("A-small-attempt2.in","r");
sys.stdin = inFile;
outFile = open("A-small-out.out","w");
sys.stdout = outFile;

caseCount = eval(input());

vowels = set(('a', 'e', 'i', 'o', 'u'));

for caseIndex in range(0, caseCount):
    data = input().split(" ");
    name = data[0];
    n = eval(data[1]);
    nVal = 0;
    
    for start in range(0, len(name)):
        for end in range(1, len(name)+1):
            cnsqCons = 0;
            for i in range(start, end):
                if(name[i] in vowels):
                    cnsqCons = 0;
                else:
                    cnsqCons += 1;
                    if(cnsqCons >= n):
                        nVal += 1;
                        break;
                    
            #print("nVal = "+str(nVal)+"\t-\tn="+str(n)+"\t-\tname["+str(start)+"]["+str(end)+"] = "+name[start:end]);
    
    print("Case #"+str(caseIndex+1)+": "+str(nVal));