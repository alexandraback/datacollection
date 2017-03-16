def find_cert(x):
    for i in range(2,int(x**0.5 +1)):
        if x % i == 0:
            return i
    return -1

count = 0
for x in range(2**15+1, 2**16, 2):
    #b = [int(k) for k in bin(x)[2:]]
    b = bin(x)[2:]
    cert = []
    for base in range(2, 11):
        val = int(b, base=base)
        c = find_cert(val)
        if c == -1:
            break
        cert.append(c)
    if len(cert) == 9:
        print(b, ' '.join([str(x) for x in cert]))
        count+=1
        if count == 50:
            break