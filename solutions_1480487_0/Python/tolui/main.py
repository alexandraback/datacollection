'''
Created on Apr 14, 2012

@author: disqiu
'''
import file

def greaterThan1(votes, X):
    votesPerc = []
            
    indMax = 0
    maxEle = max(votes)
                        
    for j in range(len(votes)):
        if maxEle == votes[j]:
            indMax = j
            
    for v in votes:
        votesPerc.append(v / X)
    votesMissing = []
            
    sumDif = 0
    for vp in votesPerc:
        dif = votesPerc[indMax] - vp
        votesMissing.append(dif)
        sumDif += dif
    
    return maxEle, sumDif, votesMissing


if __name__ == '__main__':
    lines = file.read_file('A-small-attempt3.in')
    i = 0
    write = []
    for line in lines:
        if i != 0:
            line = line.split(" ")
            N = line[0]
            votes1 = line[1:]
            votes = []
            for j in votes1:
                votes.append(float(j))
            X = sum(votes)

            maxEle, sumDif, votesMissing = greaterThan1(votes,X)
            
            if sumDif <= 1:
            
                rest = (1 - sumDif) / len(votes)
            
                res = []
                string = "Case #" + str(i) + ": "
                for vm in votesMissing:
                    res.append(vm + rest)
                    string += str((vm + rest) * 100) + " "
                
                
                write.append(string + "\n")
            else:
                print i
                # greater than 1
                removedValue = []
                v = votes[:]
                while sumDif>1:
                    v = v[:]
                    v.remove(maxEle)
                    removedValue.append(maxEle)
                    print v
                    maxEle, sumDif, votesMissing = greaterThan1(v,X)
                
                rest = (1 - sumDif) / len(votesMissing)
                print votes
                print removedValue
                string = "Case #" + str(i) + ": "
                d = 0
                for j in range(len(votes)):
                    if votes[j] in removedValue:
                        string += str(0) + " "
                    else:
                        #print d
                        string += str((votesMissing[d] + rest) * 100) + " "
                        d+=1;
                write.append(string + "\n")

        i += 1
    file.write_file(write, 'A-small-attempt3.out')
