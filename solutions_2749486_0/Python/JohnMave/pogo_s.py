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


input_file = 'pogo.in'
output_file = 'pogo.out'


def main():
    fin = open(input_file, "r")
    fout = open(output_file, "w+")
    T = int(fin.readline())
    for i in range(1, T + 1, 1):
        ans = ""
        line = fin.readline()
        [x, y] = line.split(' ')
        x = int(x)
        y = int(y)
        if x < 0:
            for j in range(0, -x, 1):
                ans += "EW"
        else:
            for j in range(0, x, 1):
                ans += "WE"
        if y < 0:
            for j in range(0, -y, 1):
                ans += "NS"
        else:
            for j in range(0, y, 1):
                ans += "SN"
        fout.write("Case #" + str(i) + ": " + ans + '\n')
    fin.close()
    fout.close()

if __name__ == "__main__":
    main()
