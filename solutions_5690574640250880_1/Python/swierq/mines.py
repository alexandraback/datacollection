#!/usr/bin/env python
import math

f = open('C-large.in','r')
lines = f.readlines()
f.close()
tests = int(lines.pop(0).strip())

class Worker(object):
    def __init__(self, params):
        self.rows,self.cols,self.mines = params
        self.map = [[ '*' for y in range(self.cols) ] for x in range(self.rows)  ]
        self.state = 1

    def work(self):
        if self.mines == 0:
            self.state = 1
            self.map = [[ '.' for y in range(self.cols) ] for x in range(self.rows)  ]
            self.map[0][0]='c'
            return True

        oks = self.rows * self.cols - self.mines

        if oks == 1:
            self.state = 1
            self.map[0][0]='c'
            return True


        if self.rows == 1 or self.cols == 1:
            if oks < 2:
                self.state = 0
                return False
            else:
                if self.rows == 1:
                    for i in range(oks):
                        self.map[0][i]='.'
                elif self.cols == 1:
                    for i in range(oks):
                        self.map[i][0]='.'
                self.state = 1
                self.map[0][0]='c'
                return True




        if oks<4:
            self.state = 0
            return False
        if (self.rows==2 or self.cols==2) and oks%2!=0:
            self.state=0
            return False

        if oks==5 or oks==7:
            self.state=0
            return False


        #now going with rows of 2s
        #.......
        #.......
        #..*****
        #..*****

        fill_cols = 0
        fill_rows = 2
        fill = 'col'

        #starting with 2collumns
        for i in range(oks):
            if fill_cols > self.cols-1 and fill_rows > self.rows-1 or oks<2:
                break;
            if fill=='col':
                if fill_cols > self.cols-1:
                    fill='row'
                    continue;

                self.map[0][fill_cols]='.'
                self.map[1][fill_cols]='.'
                oks -=2
                fill_cols+=1
                if fill_cols<=1:
                    fill='col'
                else:
                    fill = 'row'

            elif fill=="row":
                if fill_rows > self.rows-1:
                    fill='col'
                    continue;

                self.map[fill_rows][0]='.'
                self.map[fill_rows][1]='.'
                oks -=2
                fill_rows+=1
                fill='col'

      #now filling row by row:
        row = 2
        while oks > 0 and row<=self.rows-1:
            col=2
            if row>self.rows-1:
                break
            while col<=self.cols-1 and oks>0:
                oks-=1
                self.map[row][col]='.'
                col+=1
            row +=1

        self.map[0][0]='c'

    def __str__(self):
        if self.state == 0:
            return "Impossible"
        else:
            strings = [ ''.join(x) for x in self.map ]
            return "\n".join(strings)



for test in range(1,tests+1):
    w = Worker([ int(x) for x in  lines.pop(0).strip().split(" ")])
    w.work()
    print("Case #%s:" % (test,))
    print(w)

