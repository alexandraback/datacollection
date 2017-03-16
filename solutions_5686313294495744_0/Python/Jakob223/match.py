def f(N):
    ans = N
    word2sent = dict()
    word_pairs = []
    for i in xrange(N):
        f,s = raw_input().split()
        f = 'f' + f
        s = 's' + s
        word_pairs.append((f,s))
        if f in word2sent:
            word2sent[f].add(i)
        else:
            word2sent[f] = set([i])
        if s in word2sent:
            word2sent[s].add(i)
        else:
            word2sent[s] = set([i])
    unfinished = True
    while unfinished:
        unfinished = False
        for word,topics in word2sent.iteritems():
            if len(topics) == 1:
                for covered_word in word_pairs[next(iter(topics))]:
                    if covered_word in word2sent:
                        del word2sent[covered_word]
                ans -= 1
                unfinished = True
                # print word_pairs[next(iter(topics))]
                break
    num_f = sum(1 for i in word2sent.iterkeys() if i[0]=='f')
    num_s = sum(1 for i in word2sent.iterkeys() if i[0]=='s')
    return ans-max(num_f,num_s)
        
        
T = int(raw_input())
for i in xrange(1,T+1):
    print "Case #%d: %d" % (i, (f(int(raw_input()))))
    
# 4
# OZONETOWER
# WEIGHFOXTOURIST
# OURNEONFOE
# ETHER
    


    