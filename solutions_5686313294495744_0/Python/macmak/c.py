def goodlist(word1,word2,fake1,fake2):
    for w in fake1:
        if word1[w] == fake1[w]:
            return False
    for w in fake2:
        if word2[w] == fake2[w]:
            return False
    return True

T = int(input())
for case in range(T):
    N = int(input())
    topics = []
    word1 = {}
    word2 = {}
    for i in range(N):
        w1,w2 = input().split()
        topics.append((w1,w2))
        if w1 not in word1:
            word1[w1] = 0
        if w2 not in word2:
            word2[w2] = 0
        word1[w1] += 1
        word2[w2] += 1
    fakecands = []
    fake1 = {}
    fake2 = {}
    for w1,w2 in topics:
        if word1[w1] > 1 and word2[w2] > 1:
            fakecands.append((w1,w2))
            if w1 not in fake1:
                fake1[w1] = 0
            if w2 not in fake2:
                fake2[w2] = 0
            fake1[w1] += 1
            fake2[w2] += 1

    while not goodlist(word1,word2,fake1,fake2):
        need1 = []
        need2 = []
        for w in fake1:
            if word1[w] == fake1[w]:
                need1.append((fake1[w],w))
        for w in fake2:
            if word2[w] == fake2[w]:
                need2.append((fake2[w],w))
        need1.sort(reverse=True)
        need2.sort(reverse=True)

        if len(need1) > 0:
            nw1 = need1[0][1]
            frem = None
            count2 = 0
            for w1,w2 in fakecands:
                if w1 != nw1:
                    continue
                for c2,nw2 in need2:
                    if nw2 == w2:
                        if count2 < c2:
                            count2 = c2
                            frem = (w1,w2)
                        else:
                            break
            #print('remove',frem)
            #print(need1,need2)
            if frem:
                fakecands.remove(frem)
                fake1[frem[0]] -= 1
                fake2[frem[1]] -= 1
                continue

        if len(need2) > 0:
            nw2 = need2[0][1]
            for w1,w2 in fakecands:
                if w2 == nw2:
                    frem = (w1,w2)
                    break
            if frem:
                fakecands.remove(frem)
                fake1[frem[0]] -= 1
                fake2[frem[1]] -= 1
                continue            
        if len(need1) > 0:
            nw1 = need1[0][1]
            for w1,w2 in fakecands:
                if w1 == nw1:
                    frem = (w1,w2)
                    break            
            if frem:
                fakecands.remove(frem)
                fake1[frem[0]] -= 1
                fake2[frem[1]] -= 1
                continue  

    print('Case #',case+1,': ',len(fakecands),sep='')
