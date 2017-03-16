from igraph import *
import itertools
def mineSearch(r, c, m):
    if m==r*c-1:
        return (r,c,range(m),m)
    else:
        g=Graph.Lattice([r, c], circular=False)
        additionalEdges=[(v, v+r+1) for v in [cPos*r+rPos for cPos in range(0, c-1) for rPos in range(0, r-1)]]+[(v, v+r-1) for v in [cPos*r+rPos for cPos in range(0, c-1) for rPos in range(1,r)]]
        g.add_edges(additionalEdges)
        answer=(r, c, None, None)
        for mines in itertools.combinations(range(r*c), m): 
            minesAndNaturals=set([item for sublist in g.neighborhood(vertices=mines) for item in sublist])
            justNaturals=minesAndNaturals-set(mines)
            zeros=list(set(range(r*c))-set(minesAndNaturals))
            zerosAndZeroNeighbours=set([item for sublist in g.neighborhood(vertices=zeros) for item in sublist])
            justZeroNeighbours=zerosAndZeroNeighbours-set(zeros)
            zeroGraph=g.induced_subgraph(zeros)
            if zeroGraph.is_connected() and zeroGraph.vcount()>0 and justZeroNeighbours==justNaturals:
                for zero in zeros:
                    if set(g.neighbors(zero)) <= zerosAndZeroNeighbours:
                        source=zero
                        break
                answer=(r, c, mines, source)
                break
        return answer

def prettyPrint(answer):
    (r, c, mines, source)=answer
    if mines==None:
        return 'Impossible'
    else:
        output=[['.']*c for _ in range(r)]
        for v in mines:
            output[v%r][v/r]='*'
        output[source%r][source/r]='c'
        output='\n'.join([''.join(x) for x in output])
        return output

def minesweeperMaster(inputFileName):
    data = [i.strip() for i in open(inputFileName).readlines()]
    data = [x.split() for x in data]
    caseCount=int(data[0][0])
    # change based on how many lines there are in each case
    caseLength=1

    def extractCases(data, caseCount, caseLength):
        return [data[1+caseID*caseLength:1+(caseID+1)*caseLength] for caseID in range(caseCount)]
    
    cases=extractCases(data, caseCount, caseLength)
    
    def caseText(caseID, case):
        (r, c, m)=map(int, case[0])
        
        solution='\n'+prettyPrint(mineSearch(r, c, m))

        #monitoring progress:
        print(caseID)
        
        #boilerplate for pretty printing
        caseText='Case #'+str(caseID)+': '
        return caseText+str(solution)+'\n'

    output=[]
    for (caseID, case) in enumerate(cases):
        output.append(caseText(caseID+1, case))

    outputFileName=inputFileName.replace('.in','-output.txt')

    f=open(outputFileName, 'wb')
    f.write('')
    f.writelines(output)
    f.close()

67, 73, 87, 142
