import re
import urllib2
import cookielib
from time import sleep, strptime
import datetime
from urllib import urlencode
from BeautifulSoup import BeautifulStoneSoup
import json
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.utils import COMMASPACE, formatdate
import smtplib
import sys
import os


input_file = 'consonants.in'
output_file = 'consonants.out'


def main():
    fin = open(input_file, "r")
    fout = open(output_file, "w+")
    T = int(fin.readline())
    for i in range(1, T + 1, 1):
        ans = 0
        line = fin.readline()
        [L, n] = line.split(' ')
        n = int(n)
        j = 0
        t = 0
        tn = 0
        cnt = 0
        for c in L:
            if c in set('aeiou'):
                if t == 1:
                    t = 0
                tn += 1
            else:
                if t == 1:
                    cnt += 1
                else:
                    t = 1
                    cnt = 1
                if cnt >= n:
                    tn = n - 1
                else:
                    tn += 1
            j += 1
            ans += j - tn
        fout.write("Case #" + str(i) + ": " + str(ans) + '\n')
    fin.close()
    fout.close()

if __name__ == "__main__":
    main()
