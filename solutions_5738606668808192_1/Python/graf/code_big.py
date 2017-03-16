def find_cert_b(x, base):
    for i in [2,3,5,7,11,13]: #int(x**0.5 +1)):
        res = 0
        for t in x:
            res = (res * base + t) % i
        if res == 0:
            return i
    return -1

count = 0
print("Case #1:")
for x in range(2**31+1, 2**32, 2):
    #b = [int(k) for k in bin(x)[2:]]
    b = bin(x)[2:]
    cert = []
    for base in range(2, 11):
        #val = int(b, base=base)
        val = [int(t) for t in b]
        c = find_cert_b(val, base)
        if c == -1:
            break
        cert.append(c)
    if len(cert) == 9:
        print(b, ' '.join([str(x) for x in cert]))
        count+=1
        if count == 500:
            break