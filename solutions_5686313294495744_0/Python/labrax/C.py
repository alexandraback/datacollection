# python 3

tests = int(input())

for t in range(1, tests+1):
    words = int(input())
    
    all_words = []
    count_first = {}
    count_second = {}
    
    fake_first = {}
    fake_second = {}
    
    fake_total = 0
    
    for w in range(0, words):
        line = input().split(' ')
        word1 = line[0]
        word2 = line[1]
        all_words.append((word1, word2))
        count_first[word1] = count_first.get(word1, 0) + 1
        count_second[word2] = count_second.get(word2, 0) + 1
    
    for a in all_words:
        word1 = a[0]
        word2 = a[1]
        if count_first[word1] > 1 and count_second[word2] > 1:
            k1 = False
            k2 = False
            if fake_first.get(word1, 0) + 1 < count_first[word1]:
                fake_first[word1] = fake_first.get(word1, 0) + 1
                k1 = True
            if fake_second.get(word2, 0) + 1 < count_second[word2]:
                fake_second[word2] = fake_second.get(word2, 0) + 1
                k2 = True
            if k1 == True and k2 == True:
                fake_total += 1
            else:
                if k1 == True:
                    fake_first[word1] -= 1
                elif k2 == True:
                    fake_second[word2] -= 1
        #print("####", word1, word2, fake_total)
        #print(count_first, count_second)
        #print(fake_first, fake_second)
    
    output = "Case #{0}: {1}".format(t, fake_total)
    print(output)
