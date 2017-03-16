from io import StringIO
from sys import stdout

class CodeJam(object):
    def __init__(self, processor, debug=False):
        self.debug = debug
        self.processor = processor
    def processtext(self, text):
        self.process(StringIO(text), stdout)
    def processfile(self, filename):
        with open(filename) as fin, \
             open(filename + '.out', 'w') as fout:
            self.process(fin, fout)
    def process(self, fin, fout):
        tests = int(fin.readline().strip())
        if self.debug:
            print('Total {} tests...'.format(tests))
        for test in range(tests):
            if self.debug:
                print('   Processing test {}...'.format(test))
            print('Case #{}: {}'.format(test+1, self.processor(fin)), file=fout)
