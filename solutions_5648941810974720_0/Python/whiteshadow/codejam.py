__author__ = 'sushrutrathi'


with open('input.txt') as f:
    t = int(f.readline().split()[0])
    for k in range(1,t+1):


        st = f.readline().replace('\n','')
        cnt = [0]*260
        for ch in list(st):
            cnt[ord(ch)] += 1

        ans = ""

        ls = ['Z','W','G','T','R','F','O','V','S','E']
        val= ['0','2','8','3','4','5','1','7','6','9']
        nums = ['ZERO','TWO','EIGHT','THREE','FOUR','FIVE','ONE','SEVEN','SIX','NINE']

        for i in range(0,10):
            j= cnt[ord(ls[i])]
            ans += val[i]*j
            for v in nums[i]:
                cnt[ord(v)] -= j

        sorted(ans)

        print('Case #' + str(k) + ': ' + ''.join(sorted(ans)))
