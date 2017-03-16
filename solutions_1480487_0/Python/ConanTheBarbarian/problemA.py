from root.codejam.Tools import Problem
import heapq
#copy sample input and output here
sampleIn = """4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
"""
sampleOut = """Case #1: 3
Case #2: 3
Case #3: Too Bad
Case #4: 6
"""

    


        
class ProblemA(Problem):
    def solve(self, inputObj):
        line = inputObj.nextLine(sep=' ', toInt=True)
        #unpack the parameters
        #e.g: N, S, p = line[:3]; t_list = line[3:];
        N,score_list = line[0],line[1:]
        X=sum(score_list)
        inOrder=sorted(score_list)
        m=[]
        toGet=1.0*2*X/N
        for score in score_list:
            mi=(toGet-score)/X 
            if mi <0:
                mi=0.0
            m.append(mi*100)
#        for score in score_list:
#            rank=inOrder.index(score)
#            need=1.0*inOrder[N-rank-1]/X*100
#            print rank,inOrder[N-rank-1]
#            m.append(need)
        return ' '.join([str(i) for i in m])

        
        
        


if __name__ == '__main__':
    p = ProblemA('A', sampleIn)
    p.interact()
        
