def pow_r(n,m,r):
    if m==0:
        return 1
    elif m==1:
        return n%r
    a_r = pow_r(n,m//2,r)
    a_r = ((a_r * a_r) % r)
    if m%2==1:
        a_r = ((a_r * n) % r)
    return a_r

def miller_rabin(rabin_n):
    if rabin_n%2 == 0:
        return 0
    s=0
    d=rabin_n-1
    while d%2==0:
        d//=2
        s+=1
    a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
    for it in a:
        a_d = pow_r(it,d,rabin_n)
        #print(str(a_d))
        if (a_d == 1 or a_d == rabin_n-1):
            return 1
        for j in range(s-1):
            a_d = ( (a_d * a_d) % rabin_n)
            if a_d == n-1:
                return 1
    return 0

fin = open("C-small-attempt0.in","r")
n = 16
m = 50
cnt = 0
sum_ = []
for i in range(11):
    sum_.append(0)
fout = open("C-small-attempt0.out","w")
fout.write("Case #1:\n")
for i in range(1 + (1<<(n-1)),1+(1<<n),2):
    flag = 0
    print(bin(i))
    for j in range(2,11,1):
        sum_[j] = 0
        temp1 = 1
        temp2 = i
        for k in range(n):
            if temp2&1 == 1:
                sum_[j] += temp1
            temp1 *= j
            temp2 >>= 1
        print(str(sum_[j]))
        if miller_rabin(sum_[j])==1:
            flag = 1
            break
    if flag==0:
        ans_str = ""
        ans_cnt = 0
        ans_str += bin(i)[2:]+" "
        for j in range(2,11,1):
            if sum_[j]%2 == 0:
                ans_str += "2 "
                ans_cnt += 1
                continue
            k = 3
            while 1==1:
                if k*k>sum_[j]:
                    break
                if sum_[j]%k == 0:
                    ans_str += str(k) + " "
                    ans_cnt += 1
                    break
                k += 2
        ans_str += "\n"
        if ans_cnt == 9:
            cnt += 1
            fout.write(ans_str)
            if cnt==m:
                break

fin.close()
fout.close()
