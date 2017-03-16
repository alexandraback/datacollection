'''
Created on May 3, 2012

@author: jrokicki
'''
       
"""
GCJ framework (gcj.fw.framework)
 - Command Line and Package interface
 - output redirection
 - parsing case input
 - executing problem code against cases
 - testing framework
"""
import sys
import unittest
import StringIO

class Framework(object):
    class Case(object):
        def __init__(self, caseNumber, caseData=None):
            self.number = caseNumber
            self.data = caseData
            self.result = None
    
        @classmethod
        def parser(cls, f_in):
            pass
    
        def run(self):
            pass
    
        def execute(self, f_in=None):
            if self.data is None:
                self.data = self.parser(f_in)
            self.result = self.run(**self.data)
    
        def __str__(self):
            return "Case #%d: %s" % (self.number, self.result)
    
    
    class Result(object):
        def __init__(self, resultData):
            self.data = resultData
    
        def __str__(self):
            return str(self.ata)

    def __init__(self, f_in, f_out):
        sys.stdout = f_out
        self.f_in = f_in if f_in is not None else sys.stdin

    def run(self):
        nCases = int(self.f_in.readline().strip())
        for num in xrange(nCases):
            case = type(self).Case(num+1)
            case.execute( f_in=self.f_in)
            print case


    @classmethod
    def __main__(cls):
        f_in = sys.stdin
        if len(sys.argv) > 1:
            if sys.argv[1] == "-t":
                unittest.main()
                sys.exit()
            f_in = open(sys.argv[1])
        framework = cls(f_in, sys.stdout)
        framework.run()
    
class Test(unittest.TestCase):
    cases = []
    case = None
    c=[]
    
    def setUp(self):
        self.c = []
        self.defineCases()
        counter = 1
        self.cases = []
        for c in self.c:
            case = self.case(counter)
            case.data = case.parser(StringIO.StringIO(c[0]))
            self.cases.append( [case, c[1]])
    
    def defineCases(self):
        pass
    
    def tearDown(self):
        pass 

    def test_Name(self):
        self.setUp()
        for case in self.cases:
            print case[0].data, case[1]
            case[0].execute()
            self.assertEqual(case[0].result, case[1])
class node():
    def __init__(self,n):
        self.n = n
        self.c = []
    def a(self, n):
        self.c.append(n)

def walk(n,s={}):
    if n.n in s: return True
    s[n.n] = True
    for j in n.c:
        v = walk(j,s)
        if v: return True
    return False

class A(Framework):
    class Case(Framework.Case):
        def parser(self, fh):
            N = int(fh.readline().strip())
            M = [map(int, fh.readline().strip().split(" "))[1:] for x in xrange(N)]
            return {'N': N, 'M': M}
        
        def run(self,N=None, M=None):
            d = {}
            for i in xrange(1,N+1):
                d[i] = node(i)

            for i in xrange(1,N+1):
                for j in M[i-1]:
                    d[i].a(d[j])
            
            for i in xrange(1,N+1):
                v = walk(d[i],s={})
                if v: return "Yes"
            return "No"
        
class Test(Test):
    def defineCases(self):
        self.case = A.Case
        self.c = [["""3
1 2
1 3
0""", "No"],
                  ["""5
2 2 3
1 4
1 5
1 5
0""", "Yes"],
                  ["""3
2 2 3
1 3
0""", "Yes"]
                    ]
    

if __name__ == "__main__":
    A.__main__()
