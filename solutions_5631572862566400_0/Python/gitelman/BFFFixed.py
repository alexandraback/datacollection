


def getMaxCircle(BFFList):
    BFFList0 = [int(i)-1 for i in BFFList]
    bestLength = 0
    for i in range(len(BFFList)):
        curr = buildMaxCircle(BFFList0, [i], 0)
        if curr > bestLength:
            bestLength = curr
    return bestLength




# # make sure you zero index BFFList
# # assuming seed is standalone and legal
# def buildMaxCircle(BFFList, seed):
#     currCircle = seed#[:]
#     for i in range(len(BFFList)):
#         if i in currCircle:
#             continue
#         else:
#             currCircle.append(i)
#             while BFFList[currCircle[-1]] not in currCircle:
#                 currCircle.append(BFFList[currCircle[-1]])
#             if BFFList[currCircle[-1]] == currCircle[-2]: # order is important for case where there are only 2
#                 seed = currCircle[:]
#                 return buildMaxCircle(BFFList, seed)
#             elif BFFList[currCircle[-1]] == currCircle[0]:
#                 return currCircle
#             else: # bad case
#                 return seed


# make sure you zero index BFFList
# assuming seed is standalone and legal
def buildMaxCircle(BFFList, seed, bestLength):
    currCircle = seed[:]
    while BFFList[currCircle[-1]] not in currCircle:
        currCircle.append(BFFList[currCircle[-1]])
    if BFFList[currCircle[-1]] == currCircle[-2]: # order is important for case where there are only 2
        for i in range(len(BFFList)):
            if i not in currCircle:
                bestLength = buildMaxCircle(BFFList, currCircle + [i], bestLength)
    elif BFFList[currCircle[-1]] == currCircle[0]:
        if len(currCircle) > bestLength:
            bestLength = len(currCircle)
        #return currCircle
    # else: # bad case
    #     if len(seed) > bestLength:
    #         bestLength = len(seed)
    #         print bestLength
        #return seed

    return bestLength


def main():
    T = int(raw_input())
    for i in range(1, T+1):
        N = int(raw_input())
        BFFList = raw_input().split()
        print "Case #{}: {}".format(i, getMaxCircle(BFFList))


if __name__ == "__main__":
    main()



