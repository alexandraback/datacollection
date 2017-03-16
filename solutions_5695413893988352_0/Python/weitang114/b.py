import numpy as np

def run(cc, jj):
    # print 'run (%s,%s)' % (cc,jj)
    n = len(cc)
    cn = []
    jn = []
    head = True

    def choose(sel):
        l = str(len(sel[0][0]))
        sel = [(int(r[0]), int(r[1])) for r in sel]
        sel = sorted(sel, key=lambda r: abs(r[0]-r[1]))

        sel = filter(lambda r:abs(r[0]-r[1])==abs(sel[0][0]-sel[0][1]), sel )
        sel = sorted(sel, key=lambda r: r[0])
        sel = filter(lambda r:r[0]==sel[0][0], sel )
        sel = sorted(sel, key=lambda r: r[1])
        result = sel[0]
        return (('%0'+ l + 'd') % result[0], ('%0' + l + 'd') % result[1])

    for i, (c,j) in enumerate(zip(cc,jj)):
        if head and c == j == '?':
            if i == n-1:
                cn.append('0')
                jn.append('0')
                break
            if cc[i+1] == jj[i+1] == '?':
                cn.append('0')
                jn.append('0')
            elif cc[i+1] != '?' and jj[i+1] != '?':
                if i+2 == n:
                    if cc[i+1] < jj[i+1]:
                    
                        sel1 = ('0'+cc[i+1], '0'+jj[i+1])
                        sel2 = ('1'+cc[i+1], '0'+jj[i+1])
                        sel = choose([sel1, sel2])
                        cn.extend(sel[0])
                        jn.extend(sel[1])
                    elif cc[i+1] > jj[i+1]:
                        sel1 = ('0'+cc[i+1], '0'+jj[i+1])
                        sel2 = ('0'+cc[i+1], '1'+jj[i+1])
                        sel = choose([sel1, sel2])
                        cn.extend(sel[0])
                        jn.extend(sel[1])
                    else:
                        cn.append('0')
                        jn.append('0')
                        cn.append(cc[i+1])
                        jn.append(jj[i+1])

                    break
                cn.append(cc[i+1])
                jn.append(jj[i+1])
                if cc[i+1] == jj[i+1]:
                    r = run(cc[i+2:], jj[i+2:])
                    cn.extend(r[0])
                    jn.extend(r[1])
                    break
                elif cc[i+1] < jj[i+1]:
                    cn.extend(list(cc[i+2:].replace('?', '9')))
                    jn.extend(list(jj[i+2:].replace('?', '0')))
                    break
                elif cc[i+1] > jj[i+1]:
                    cn.extend(list(cc[i+2:].replace('?', '0')))
                    jn.extend(list(jj[i+2:].replace('?', '9')))
                    break
            elif cc[i+1] != '?' and jj[i+1] == '?':
                if i+2 == n:
                    cn.append(cc[i+1])
                    jn.append(cc[i+1])
                    break
                #3 cases: ==, jj[i+1] = cc[i+1] +- 1
                results = []
                cm = int(cc[i+1])
                for jm in [cm-1, cm, cm+1]:
                    if jm < cm:
                        r1 = str(cm) + (cc[i+2:].replace('?', '0'))
                        r2 = str(jm) + (jj[i+2:].replace('?', '9'))
                        results.append((r1, r2))
                    elif jm > cm:
                        r1 = str(cm) + (cc[i+2:].replace('?', '9'))
                        r2 = str(jm) + (jj[i+2:].replace('?', '0'))
                        results.append((r1, r2))
                    else:
                        res = run(cc[i+2:], jj[i+2:])
                        # print 'res', res
                        results.append((str(cm)+res[0], str(jm)+res[1]))
                # print 'results:', results
                results = [(int(r[0]), int(r[1])) for r in results]
                results = sorted(results, key=lambda r: abs(r[0]-r[1]))

                results = filter(lambda r:abs(r[0]-r[1])==abs(results[0][0]-results[0][1]), results )
                results = sorted(results, key=lambda r: r[0])
                results = filter(lambda r:r[0]==results[0][0], results )
                results = sorted(results, key=lambda r: r[1])
                result = results[0]
                cn.extend(list(str(result[0])))
                jn.extend(list(str(result[1])))
                break
                
            elif cc[i+1] == '?' and jj[i+1] != '?':
                if i+2 == n:
                    cn.append(jj[i+1])
                    jn.append(jj[i+1])
                    break
                #3 cases: ==, jj[i+1] = cc[i+1] +- 1
                results = []
                jm = int(jj[i+1])
                for cm in [jm-1, jm, jm+1]:
                    if jm < cm:
                        r1 = str(cm) + (cc[i+2:].replace('?', '0'))
                        r2 = str(jm) + (jj[i+2:].replace('?', '9'))
                        results.append((r1, r2))
                    elif jm > cm:
                        r1 = str(cm) + (cc[i+2:].replace('?', '9'))
                        r2 = str(jm) + (jj[i+2:].replace('?', '0'))
                        results.append((r1, r2))
                    else:
                        res = run(cc[i+2:], jj[i+2:])
                        # print 'res:', res
                        results.append((str(cm)+res[0], str(jm)+res[1]))
                # print results
                results = [(int(r[0]), int(r[1])) for r in results]
                results = sorted(results, key=lambda r: abs(r[0]-r[1]))
                results = filter(lambda r:abs(r[0]-r[1])==abs(results[0][0]-results[0][1]), results )
                results = sorted(results, key=lambda r: r[0])
                results = filter(lambda r:r[0]==results[0][0], results )
                results = sorted(results, key=lambda r: r[1])
                result = results[0]
                cn.extend(list(str(result[0])))
                jn.extend(list(str(result[1])))
                break
        elif c == '?' or j == '?':
            if i == n-1:
                r = c if j == '?' else j
                cn.append(r)
                jn.append(r)
                break
            else:
                if c != '?' and j == '?':
                    results = []
                    cm = int(c)
                    for jm in [cm-1, cm, cm+1]:
                        if jm < cm:
                            r1 = str(cm) + (cc[i+1:].replace('?', '0'))
                            r2 = str(jm) + (jj[i+1:].replace('?', '9'))
                            results.append((r1, r2))
                        elif jm > cm:
                            r1 = str(cm) + (cc[i+1:].replace('?', '9'))
                            r2 = str(jm) + (jj[i+1:].replace('?', '0'))
                            results.append((r1, r2))
                        else:
                            res = run(cc[i+1:], jj[i+1:])
                            # print 'res', res
                            results.append((str(cm)+res[0], str(jm)+res[1]))
                    # print 'results:', results
                    results = [(int(r[0]), int(r[1])) for r in results]
                    results = sorted(results, key=lambda r: abs(r[0]-r[1]))
                    results = filter(lambda r:abs(r[0]-r[1])==abs(results[0][0]-results[0][1]), results )
                    results = sorted(results, key=lambda r: r[0])
                    results = filter(lambda r:r[0]==results[0][0], results )
                    results = sorted(results, key=lambda r: r[1])
                    result = results[0]
                    cn.extend(list(str(result[0])))
                    jn.extend(list(str(result[1])))
                    break
                    
                elif c == '?' and j != '?':
                    results = []
                    jm = int(j)
                    for cm in [jm-1, jm, jm+1]:
                        if jm < cm:
                            r1 = str(cm) + (cc[i+1:].replace('?', '0'))
                            r2 = str(jm) + (jj[i+1:].replace('?', '9'))
                            results.append((r1, r2))
                        elif jm > cm:
                            r1 = str(cm) + (cc[i+1:].replace('?', '9'))
                            r2 = str(jm) + (jj[i+1:].replace('?', '0'))
                            results.append((r1, r2))
                        else:
                            res = run(cc[i+1:], jj[i+1:])
                            results.append((str(cm)+res[0], str(jm)+res[1]))
                    results = [(int(r[0]), int(r[1])) for r in results]
                    results = sorted(results, key=lambda r: abs(r[0]-r[1]))
                    results = filter(lambda r:abs(r[0]-r[1])==abs(results[0][0]-results[0][1]), results )
                    results = sorted(results, key=lambda r: r[0])
                    results = filter(lambda r:r[0]==results[0][0], results )
                    results = sorted(results, key=lambda r: r[1])
                    result = results[0]
                    cn.extend(list(str(result[0])))
                    jn.extend(list(str(result[1])))
                    break
        else:
            if i == n-1:
                cn.append(c)
                jn.append(j)
                break
            cm = int(c)
            jm = int(j)
            if jm < cm:
                r1 = str(cm) + (cc[i+1:].replace('?', '0'))
                r2 = str(jm) + (jj[i+1:].replace('?', '9'))
            elif jm > cm:
                r1 = str(cm) + (cc[i+1:].replace('?', '9'))
                r2 = str(jm) + (jj[i+1:].replace('?', '0'))
            else:
                res = run(cc[i+1:], jj[i+1:])
                r1 = str(cm) + res[0]
                r2 = str(jm) + res[1]
            cn.extend(list(r1))
            jn.extend(list(r2))
            break
                
                
    # print cn

    # print jn
    return ''.join(cn), ''.join(jn) 
        
# def run_small(cc, jj):
    # cn = range(1000)
    # print cn
    # jn = range(1000)
    # for c in cn:
        # if len(str(c)) != len(cc):
            # cn.remove(c)
            # continue
        # for j,c2 in enumerate(cc):
            # if c2 != '?' and c2 != str(c)[j]:
                # cn.remove(c)

    # print len(jj)
    # for j in jn:
        # # print len(str(j))
        # if j == 403:
            # print len(str(j))
        # if len(str(j)) != len(jj):
            # print j, 
            # jn.remove(j)
            # continue
        # for i,j2 in enumerate(jj):
            # if j2 != '?' and j2 != str(j)[i]:
                # jn.remove(j)
    
    # # print cn, jn
    # cn = sorted(cn)
    # jn = sorted(jn)
    # pairs = []
    # for c in cn:
        # for j in jn:
            # pairs.append((c,j))

    # pairs = sorted(pairs, key=lambda a: abs(a[0]-a[1]))
    # pairs = filter(lambda a:abs(a[0]-a[1])==abs(pairs[0][0]-pairs[0][1]), pairs)
    # pairs = sorted(pairs, key=lambda a: a[0])
    # pairs = filter(lambda a:a[0]==pairs[0][0], pairs)
    # pairs = sorted(pairs, key=lambda a: a[1])

    # print pairs[0]
    # return pairs[0]

def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        n, m = [s for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
         
        
        l = str(len(n))
        res1, res2 = run(n, m)

        print ("Case #%d: %0" + l + "d %0" + l + "d") %(i, int(res1), int(res2))
        # check out .format's specification for more formatting options

main()
