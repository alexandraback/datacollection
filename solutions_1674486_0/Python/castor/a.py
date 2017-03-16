#!/usr/bin/python

import sys

def solve(input):

    def getParent(i, input):
        ps=set()
        ps.add(i)
        for _i in input[i]:
            ps.update(getParent(_i, input))
        return ps

    for item in input:
        if len(item)>1:
            ps=set()
            for _item in item:
                _ps=getParent(_item, input)
                if ps&_ps:
                    return 'Yes'
                ps.update(_ps)
    else:
        return 'No'

if __name__ == '__main__':
    with open(sys.argv[2], 'w') as out:
        with open(sys.argv[1]) as f:
            for i in range(int(f.readline())): # Case
                input=[]
                for j in range(int(f.readline())): # classes
                    input.append(list(map(lambda item:int(item)-1, f.readline().split()))[1:])
                result=solve(input)
                print('Case #{}: {}'.format(i+1,result), file=out)
