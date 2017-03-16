def deceitfulWar(inputFileName):
    data = [i.strip() for i in open(inputFileName).readlines()]
    data = [x.split() for x in data]
    caseCount=int(data[0][0])
    # change based on how many lines there are in each case
    caseLength=3

    def extractCases(data, caseCount, caseLength):
        return [data[1+caseID*caseLength:1+(caseID+1)*caseLength] for caseID in range(caseCount)]
    
    cases=extractCases(data, caseCount, caseLength)

    def caseText(caseID, case):
        weightCount=int(case[0][0])

        def truthfulPlay(case):
            nBlocks=map(float,case[1])
            kBlocks=map(float,case[2])
            nBlocks.sort(reverse=True)
            kBlocks.sort()        
            
            naomiScore=0
            
            while nBlocks!=[]:
                naomiBlock=nBlocks.pop()
                kenBlock = next((block for block in kBlocks if block>naomiBlock), None)
                if kenBlock != None:
                    kBlocks.remove(kenBlock)
                else:
                    kBlocks.pop(0)
                    naomiScore+=1

            return naomiScore

        def dishonestPlay(case):
            # we make use of the fact that all the masses given to Ken and Naomi are distinct
            nBlocks=map(float,case[1])
            kBlocks=map(float,case[2])
            nBlocks.sort()
            kBlocks.sort(reverse=True)

            naomiScore=0

            # print nBlocks
            # print kBlocks
            
            while nBlocks[-1]>kBlocks[-1]:
                kenBlock=kBlocks.pop()
                naomiBlock = next((block for block in nBlocks if block>kenBlock), None)
                nBlocks.remove(naomiBlock)
                # print (naomiBlock, kenBlock)
                naomiScore+=1
                if nBlocks==[]:
                    break

            return naomiScore
        
        solution=str(dishonestPlay(case))+' '+str(truthfulPlay(case))

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
