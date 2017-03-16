#!/usr/bin/python

import re
import sys

class Tetris:
    filename = sys.argv[1]
    outputStream = sys.stdout

    def solve(self) :
        self.loadFile()
        self.steps()
    
    def loadFile(self) :
        self.inputStream = open(self.filename, "r")
        l = self.inputStream.readline();
        T = re.match("[0-9]+", l)
        self.T = int(T.group(0))

    def steps(self) :
        for i in range(self.T) :
            self.case = i
            X, R, C = re.split(" +", self.inputStream.readline())
            self.X = int(X)
            self.R = int(R)
            self.C = int(C)
            self.step()

    def step(self) :
        
        # donuts-omino
        if self.X > 6 :
            self.thereWillBeHole()
            return

        if self.X == 1 :
            self.canBeFilled();
            return
            
        if self.tooBig() :
            return

        if self.match() :
            return

        if self.X == 2 :
            self.canBeFilled();
            return

        if self.doNotFit() :
            return

        if self.pentonimos() :
            return

        if self.hexaminos() :
            return
        
        self.canBeFilled()

    def thereWillBeHole(self) :
        self.outputStream.write("Case #" + str(self.case+1) + ": RICHARD\n")

    def canBeFilled(self) :
        self.outputStream.write("Case #" + str(self.case+1) + ": GABRIEL\n")

    def tooBig(self) :
        if self.R < self.C :
            self.minSide = self.R
            self.maxSide = self.C
        else :
            self.minSide = self.C
            self.maxSide = self.R

        if self.maxSide < self.X :
            self.thereWillBeHole()
            return True

        # TODO : check it
        if self.X > self.minSide*2 and self.X > 2 :
            self.thereWillBeHole()
            return True
        return False

    def match(self) :
        if self.C*self.R % self.X != 0 :
            self.thereWillBeHole()
            return True
        return False

    def doNotFit(self) :

        if self.minSide == 2 and self.X >= 4 :
            self.thereWillBeHole()
            return True

        return False

    def pentonimos(self) :

        if self.X != 5 :
            return False;

            if self.minSide == 3 and self.maxSide == 5 :
                self.thereWillBeHole();
                return True;

        return False;

    def hexaminos(self) :

        if self.X != 6 :
            return False;

            if self.minSide == 3 :
                self.thereWillBeHole();
                return True;

            if self.minSide == 3 and self.maxSide == 4 :
                self.thereWillBeHole();
                return True;     

            
        return False;
        

tetris = Tetris()
tetris.solve();
                 
