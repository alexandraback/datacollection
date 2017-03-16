from root.codejam.Tools import Problem

#copy sample input and output here
sampleIn = """2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
"""
sampleOut = """Case #1: 3
Case #2: 2
Case #3: 1
Case #4: 3
"""

from itertools import chain,combinations
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

class ProblemC(Problem):
    def solve(self, inputObj):
        line = inputObj.nextLine(sep=' ', toInt=True)
        N,numbers= line[0],line[1:]
        record=dict()
        for s in powerset(numbers):
            if len(s)==0: continue
            key=sum(s)
            if record.has_key(key):
                return '\n'+ ' '.join(map(str,record[key]))+'\n'+' '.join(map(str,s))
                break
            else:
                record[key]=s
        return 'Impossible'




if __name__ == '__main__':
    p = ProblemC('C', sampleIn)
    p.interact()
        
