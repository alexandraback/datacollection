
with open('D-large.in', 'r') as dat, open('output.txt', '+w') as output:
    n = int(dat.readline())
    for i in range(n):
        t = int(dat.readline())
        n_bag = list(map(float, dat.readline().strip('\n').split()))
        k_bag = list(map(float, dat.readline().strip('\n').split()))
        idx = [0] * t + [1] * t
        

        

        w_score = 0
        d_score = 0
        w_temp = 0
        d_temp = 0
        idx = [x for (y, x) in sorted(zip(n_bag + k_bag, idx), reverse = True)]
        
        
        
        for r in idx:
            if r:
                w_temp += 1
            else:
                if w_temp > 0:
                    w_temp -= 1
                else:
                    w_score += 1
        for r in idx:
            if r:
                if d_temp > 0:
                    d_temp -= 1
                else:
                    d_score -= 1
            else:
                if d_temp >= 0:
                    d_score += 1
                d_temp += 1
 
        #print(t, idx)
       # print('Case #' + str(i + 1) + ': ' + str(d_score) + ' ' + str(w_score))
        output.write('Case #' + str(i + 1) + ': ' + str(d_score) + ' ' + str(w_score) + '\n')