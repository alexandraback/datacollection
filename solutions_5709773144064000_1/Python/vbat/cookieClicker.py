def cookieClicker(inputFileName):
    data = [i.strip() for i in open(inputFileName).readlines()]
    data = [x.split() for x in data]
    caseCount=int(data[0][0])
    caseLength=1

    def extractCases(data, caseCount, caseLength):
        return [data[1+caseID*caseLength:1+(caseID+1)*caseLength] for caseID in range(caseCount)]
    
    cases=extractCases(data, caseCount, caseLength)

    def caseText(caseID, case):
        (c, f, x)=map(float, case[0])

        def solveCase(c, f, x):
            baseRate=2
            t=0
            curCookies=0
            curFarms=0

            while curCookies < x:
                currentRate=baseRate+f*curFarms
                if x/currentRate < c/currentRate + x/(currentRate+f):
                    # if it is no longer worth it to buy the next farm
                    dt=x/currentRate
                    t+=dt
                    curCookies = x
                    # algorithm should terminate
                else:
                    dt=c/currentRate
                    t+=dt
                    curFarms+=1

            return t
        
        solution=solveCase(c, f, x)

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
