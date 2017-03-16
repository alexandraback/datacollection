from random import random
import requests
from bs4 import BeautifulSoup
import re
from time import sleep
from os import system

def factordb(a):
    system('yafu-x64.exe factor(' + str(a) + ') > tmpfile &')
    f = open('tmpfile', 'r')
    content = f.read()
    num = re.findall('P\d+ = (\d+)', content)[0]
    f.close()
    '''
    res = requests.get('http://factordb.com/index.php?query=' + str(a))
    soup = BeautifulSoup(res.content, 'html.parser')
    t = soup.find_all('table')[1].find_all('tr')[2].find_all('td')[2].find_all('a')[1].text
    num = re.findall('^(\d+)', t)[0]
    '''
    print 'factor ' + str(a) + ': ' + str(num)
    return int(num)

def arr2int(arr, base):
    tmp = 0
    for i in xrange(len(arr)):
        tmp = tmp * base + arr[i]
    return tmp

ans = []
ans.append([])
ans.append([])
tested = []

def init():
    for n in xrange(2):
        N = (n + 1) * 16
        s = [1 for i in xrange(N)]
        cnt = 0
        limit = 50
        if N == 32:
            limit = 500
        while cnt < limit:
            print str(cnt) + '...'
            for i in xrange(1, N - 2):
                s[i] = int(random() * 2)
            flag = True
            tmp = []
            XD = arr2int(s, 10)
            tmp.append(XD)
            if XD in tested:
                continue
            tested.append(XD)
            for i in xrange(2, 11):
                v = arr2int(s, i)
                f = factordb(v)
                tmp.append(f)
                if v == f:
                    flag = False
                    break
            if flag:
                ans[n].append(tmp)
                cnt = cnt + 1

if __name__ == '__main__':
    init()
    while True:
        filename = raw_input('input_filename: ')
        f = open(filename, 'r')
        of = open('out', 'w')
        cases = 0
        cnt = 0
        for line in f:
            if cases == 0:
                cases = int(line)
            else:
                cnt = cnt + 1
                of.write('Case #' + str(cnt) + ':\n')
                arr = line.split(' ')
                N = int(arr[0]) / 16 - 1
                J = int(arr[1])
                for i in xrange(J):
                    s = ''
                    for j in xrange(10):
                        if j > 0:
                            s += ' '
                        s += str(ans[N][i][j])
                    of.write(s + '\n')
        of.close()
        f.close()
