def run():
    caseCount = int(input())
    for caseIndex in range(caseCount):
        pancakeStr = input()
        stack = [0 if x=='-' else 1 for x in pancakeStr]
        stack = stack[::-1]
        result = 0
        for index, x in enumerate(stack):
            if x == 0:
                result += 1
                for i in range(index,len(stack)):
                    stack[i] = (stack[i]+1)%2

        print("Case #%d: %d" % (caseIndex+1, result))


run()
