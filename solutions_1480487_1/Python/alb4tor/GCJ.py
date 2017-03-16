'''
Created on 18 mars 2012

@author: gnugnu
'''

import sys

class InputFile(object):
    '''
    classdocs
    '''
    def __init__(self, filename=""):
        '''
        Constructor
        '''
        if filename == "":
            filename = sys.argv[1]
            
        self.full_content = open(filename, "r").readlines()
        self.size = int(self.full_content[0])
        self.idx = 0
    def __iter__(self):
        return self

    def __len__(self):
        return self.size

    def next(self):
        self.idx += 1
        try:
            return self.full_content[self.idx].rstrip("\n")
        except IndexError:
            raise StopIteration
    @property
    def case(self):
        return self.idx

class Output(object):
    def __init__(self, filename=""):
        self.case = 0

    def prt(self, data):
        self.case += 1
        self._prt("Case #%d: %s" % (self.case, str(data)))
    def _prt(self, data):
        print data

    def close(self):
        pass

class OutputFile(Output):
    def __init__(self, filename):
        Output.__init__(self)
        self.fp = open(filename, "w")

    def _prt(self, data):
        self.fp.write(data+"\n")

    def close(self):
        self.fp.close()


